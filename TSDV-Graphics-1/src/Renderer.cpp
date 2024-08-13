#include "Renderer.h"

void GuichernoEngine::Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void GuichernoEngine::Renderer::SwapBuffers(Window window)
{
	glfwSwapBuffers(window.GetGLFWwindow());
}
