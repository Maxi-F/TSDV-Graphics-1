#include "Renderer.h"
#include "iostream"

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"out vec4 vertexColor;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"   vertexColor = vec4(0.0f, 1.0f, 0.2f, 1.0f);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"in vec4 vertexColor;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vertexColor;\n"
"}\0";

int GuichernoEngine::Renderer::vertexCount = 0;
float GuichernoEngine::Renderer::vertices[];

void GuichernoEngine::Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void GuichernoEngine::Renderer::SwapBuffers(Window window)
{
	glfwSwapBuffers(window.GetGLFWwindow());
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
}

void GuichernoEngine::Renderer::GenerateBuffer()
{
	glewInit();

	GenerateShaders();

	float* verticesToBuffer = new float[vertexCount];

	for (int i = 0; i < vertexCount; i++) 
	{
		verticesToBuffer[i] = vertices[i];
	}

	unsigned int VBO;

	// Generate a buffer in VRAM.
	glGenBuffers(1, &VBO);

	// Bind the buffer to a buffer type for interpretation.
	// ARRAY_BUFFER in this case binds it as an array of vertices.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Set data on the buffer.
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexCount, verticesToBuffer, GL_STATIC_DRAW);

	// Create the layout for the vertices
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	std::cout << "Set Everything" << std::endl;

	delete[] verticesToBuffer;
}

void GuichernoEngine::Renderer::DrawArrays(BufferPointer pointer)
{
	glDrawArrays(GL_TRIANGLES, pointer.start, pointer.end);
}

GuichernoEngine::BufferPointer GuichernoEngine::Renderer::AddVertices(float verticesToAdd[], int count) 
{
	for (int i = 0; i < count; i++)
	{
		vertices[vertexCount + i] = verticesToAdd[i];
	}

	BufferPointer pointer = { vertexCount, vertexCount + count };

	vertexCount += count;

	return pointer;
}
