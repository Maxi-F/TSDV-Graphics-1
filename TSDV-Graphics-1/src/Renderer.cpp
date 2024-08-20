#include "Renderer.h"


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

void GuichernoEngine::Renderer::GenerateBuffer()
{
	glewInit();

	float* verticesToBuffer = new float[vertexCount];

	for (int i = 0; i < vertexCount; i++) 
	{
		verticesToBuffer[i] = vertices[i];
	}

	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesToBuffer), verticesToBuffer, GL_STATIC_DRAW);

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
