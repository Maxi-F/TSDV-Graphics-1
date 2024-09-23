#include "Renderer.h"
#include "iostream"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

const int MAX_INDEX_COUNT = 256;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec4 color;\n"
"out vec4 vertexColor;\n"
"uniform vec4 u_Tint;\n"
"uniform mat4 u_MVP;\n"
"void main()\n"
"{\n"
"   gl_Position = u_MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"   vertexColor = u_Tint * color;\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"in vec4 vertexColor;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vertexColor;\n"
"}\0";

unsigned int shaderProgram;
glm::mat4 view;
GuichernoEngine::Window window;

void GuichernoEngine::Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void GuichernoEngine::Renderer::SwapBuffers(Window windowToSwap)
{
	glfwSwapBuffers(windowToSwap.GetGLFWwindow());
}

void GuichernoEngine::Renderer::Init(Window gmWindow)
{
	glewInit();

	GenerateShaders();

	view = glm::mat4(1.0f);
	window = gmWindow;
}

void GuichernoEngine::Renderer::GenerateShaders()
{
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	else {
		std::cout << "Compile vertex success..." << std::endl;
	}

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	int fragmentSuccess;
	char fragmentInfoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentSuccess);

	if (!fragmentSuccess)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, fragmentInfoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << fragmentInfoLog << std::endl;
	}
	else {
		std::cout << "Compile fragment success..." << std::endl;
	}

	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int linkSuccess;
	char linkInfoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkSuccess);

	if (!linkSuccess)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, linkInfoLog);
		std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << linkInfoLog << std::endl;
	}
	else {
		std::cout << "Link shaders success..." << std::endl;
	}

	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void GuichernoEngine::Renderer::SetMVP(glm::mat4 proj, glm::mat4 viewToUse, glm::mat4 model)
{
	glm::mat4 mvp = proj * viewToUse * model;

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "u_MVP"), 1, GL_FALSE, &mvp[0][0]);
}

void GuichernoEngine::Renderer::SetColor(Color tint)
{
	glm::vec4 tintToUse = glm::vec4(tint.r, tint.g, tint.b, tint.a);
	glUniform4fv(glGetUniformLocation(shaderProgram, "u_Tint"), 1, &tintToUse[0]);
}

GuichernoEngine::BufferData GuichernoEngine::Renderer::GenerateBuffer(float vertices[], unsigned int vertexCount, unsigned int count, ShapeType shapeType)
{
	unsigned int indexCount = 0;
	float* verticesToBuffer = new float[vertexCount];

	for (unsigned int i = 0; i < vertexCount; i++)
	{
		verticesToBuffer[i] = vertices[i];
	}

	unsigned int* indicesToBuffer = GenerateIndices(vertices, vertexCount, count, indexCount, shapeType);

	unsigned int VBO;
	// Generate a buffer in VRAM.
	glGenBuffers(1, &VBO);
	// Bind element buffer for indices
	unsigned int IBO;
	glGenBuffers(1, &IBO);

	BufferData bufferData = { VBO, IBO, verticesToBuffer, indicesToBuffer, vertexCount, indexCount };
	SetData(bufferData);

	return bufferData;
}

void GuichernoEngine::Renderer::SetData(BufferData bufferData) 
{
	const unsigned int POSITION_FLOATS_LENGTH = 3;
	const unsigned int COLOR_FLOATS_LENGTH = 4;
	const unsigned int FULL_VERTEX_LENGTH = POSITION_FLOATS_LENGTH + COLOR_FLOATS_LENGTH;

	// Bind the buffer to a buffer type for interpretation.
	// ARRAY_BUFFER in this case binds it as an array of vertices.
	glBindBuffer(GL_ARRAY_BUFFER, bufferData.VBO);

	// Set data on the buffer.
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * bufferData.vertexCount, bufferData.vertices, GL_STATIC_DRAW);

	// Create the layout for the vertices
	glVertexAttribPointer(0, POSITION_FLOATS_LENGTH, GL_FLOAT, GL_FALSE, FULL_VERTEX_LENGTH * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, COLOR_FLOATS_LENGTH, GL_FLOAT, GL_FALSE, FULL_VERTEX_LENGTH * sizeof(float), (void*)(POSITION_FLOATS_LENGTH * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferData.IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * bufferData.indexCount, bufferData.indices, GL_STATIC_DRAW);
}

void GuichernoEngine::Renderer::DrawElements(BufferData bufferData, glm::mat4 model, Color tint)
{
	SetData(bufferData);
	SetMVP(window.GetProjection(), view, model);
	SetColor(tint);

	glDrawElements(GL_TRIANGLES, bufferData.indexCount, GL_UNSIGNED_INT, (void*)0);
}

bool GuichernoEngine::Renderer::isSameVertex(float someVertices[], float otherVertices[], unsigned int vertexIndex, unsigned int otherVertexIndex, unsigned int vertexFloatCount) 
{
	for (unsigned int i = 0; i < vertexFloatCount; i++) 
	{
		if (someVertices[vertexIndex + i] != otherVertices[otherVertexIndex + i]) 
		{
			return false;
		}
	}
	
	return true;
}

unsigned int* GuichernoEngine::Renderer::GenerateIndices(float vertices[], unsigned int vertexCount, unsigned int floatPerVertexCount, unsigned int& indexCount, ShapeType shapeType)
{
	std::cout << shapeType << std::endl;
	unsigned int* indices = new unsigned int[MAX_INDEX_COUNT] {};
	unsigned int uniqueVertexCount = 0;

	for (unsigned int i = 0; i < vertexCount; i += floatPerVertexCount)
	{
		int vertexInArrayIndex = -1;

		for (unsigned int j = 0; j < i; j += floatPerVertexCount)
		{
			if (isSameVertex(vertices, vertices, j, i, floatPerVertexCount)) {
				vertexInArrayIndex = j;
				break;
			};
		}

		if (vertexInArrayIndex != -1)
		{
			indices[indexCount] = static_cast<unsigned int>(vertexInArrayIndex);
		}
		else
		{	
			indices[indexCount] = uniqueVertexCount;
			uniqueVertexCount++;
		}

		indexCount++;
	}

	switch (shapeType) {
		case TRIANGLE:
			return indices;
		case SQUARE:
			unsigned int* squareIndices = new unsigned int[6] {indices[0], indices[1], indices[2], indices[0], indices[2], indices[3]};
			indexCount = 6;
			delete[] indices;
			return squareIndices;
	}

	return indices;
}
