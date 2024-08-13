#include "Renderer.h"

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

	float vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void GuichernoEngine::Renderer::Draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
