#include "Window.h"

GuichernoEngine::Window::Window(int width, int heigth, const char* windowName)
{
	this->gmWindow = glfwCreateWindow(width, heigth, windowName, NULL, NULL);
}

GLFWwindow* GuichernoEngine::Window::GetGLFWwindow()
{
	return gmWindow;
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
