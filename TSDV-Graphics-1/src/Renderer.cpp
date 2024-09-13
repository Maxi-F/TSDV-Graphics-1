#include "Renderer.h"
#include "iostream"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

const int MAX_INDEX_COUNT = 256;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"out vec4 vertexColor;\n"
"uniform mat4 u_MVP;\n"
"void main()\n"
"{\n"
"   gl_Position = u_MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"   vertexColor = vec4(0.0f, 1.0f, 0.2f, 1.0f);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"in vec4 vertexColor;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vertexColor;\n"
"}\0";

void GuichernoEngine::Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void GuichernoEngine::Renderer::SwapBuffers(Window window)
{
	glfwSwapBuffers(window.GetGLFWwindow());
}

void GuichernoEngine::Renderer::Init()
{
	glewInit();

	GenerateShaders();
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


	unsigned int shaderProgram;
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

	glm::mat4x4 proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "u_MVP"), 1, GL_FALSE, &proj[0][0]);

	std::cout << "TEST: " << glGetError() << std::endl;
}

GuichernoEngine::BufferData GuichernoEngine::Renderer::GenerateBuffer(float vertices[], unsigned int vertexCount, unsigned int count)
{
	unsigned int indexCount = 0;
	float* verticesToBuffer = new float[vertexCount];

	for (unsigned int i = 0; i < vertexCount; i++)
	{
		verticesToBuffer[i] = vertices[i];
	}

	unsigned int* indicesToBuffer = GenerateIndices(vertices, vertexCount, count, indexCount);

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
	// Bind the buffer to a buffer type for interpretation.
	// ARRAY_BUFFER in this case binds it as an array of vertices.
	glBindBuffer(GL_ARRAY_BUFFER, bufferData.VBO);

	// Set data on the buffer.
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * bufferData.vertexCount, bufferData.vertices, GL_STATIC_DRAW);

	// Create the layout for the vertices
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferData.IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * bufferData.indexCount, bufferData.indices, GL_STATIC_DRAW);
}

void GuichernoEngine::Renderer::DrawElements(BufferData bufferData)
{
	SetData(bufferData);

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

unsigned int* GuichernoEngine::Renderer::GenerateIndices(float vertices[], unsigned int vertexCount, unsigned int floatPerVertexCount, unsigned int& indexCount)
{
	unsigned int* indices = new unsigned int[MAX_INDEX_COUNT];
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

	return indices;
}
