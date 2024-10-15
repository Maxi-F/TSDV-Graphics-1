#include "Renderer.h"
#include "iostream"
#include "Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

const int MAX_INDEX_COUNT = 256;

glm::mat4 view;
GuichernoEngine::Window window;
std::map<int, GuichernoEngine::Shader> GuichernoEngine::Renderer::Shaders;

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
	Shader shader = Shader("shaders/color.vert", "shaders/color.frag", ShaderType::Shape);
	Shaders[static_cast<int>(ShaderType::Shape)] = shader;
}

void GuichernoEngine::Renderer::SetMVP(glm::mat4 proj, glm::mat4 viewToUse, glm::mat4 model, ShaderType shaderType)
{
	glm::mat4 mvp = proj * viewToUse * model;

	Shaders[static_cast<int>(shaderType)].SetMat4("u_MVP", mvp);
}

void GuichernoEngine::Renderer::SetColor(Color tint, ShaderType shaderType)
{
	glm::vec4 tintToUse = glm::vec4(tint.r, tint.g, tint.b, tint.a);

	Shaders[static_cast<int>(shaderType)].SetVec4("u_Tint", tintToUse);
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

void GuichernoEngine::Renderer::DrawElements(BufferData bufferData, glm::mat4 model, Color tint, ShaderType type)
{
	Shaders[static_cast<int>(type)].Use();

	SetData(bufferData);
	SetMVP(window.GetProjection(), view, model, type);
	SetColor(tint, type);

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
