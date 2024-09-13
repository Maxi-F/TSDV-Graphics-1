#include "Window.h"

GuichernoEngine::Window::Window() {
	this->gmWindow = NULL;
	this->projection = NULL;
}

GuichernoEngine::Window::Window(int width, int heigth, const char* windowName)
{
	this->gmWindow = glfwCreateWindow(width, heigth, windowName, NULL, NULL);
	this->projection = glm::ortho(0.0f, (float)width, 0.0f, (float)heigth, -1.0f, 1.0f);
}

GLFWwindow* GuichernoEngine::Window::GetGLFWwindow()
{
	return gmWindow;
}

glm::mat4 GuichernoEngine::Window::GetProjection()
{
	return projection;
}

void GuichernoEngine::Window::MakeCurrent()
{
	glfwMakeContextCurrent(this->gmWindow);
}

bool GuichernoEngine::Window::ShouldClose()
{
	return glfwWindowShouldClose(this->gmWindow);
}

bool GuichernoEngine::Window::IsWindowOpen()
{
	return this->gmWindow;
}
