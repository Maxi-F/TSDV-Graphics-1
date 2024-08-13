#include "Window.h"

Window::Window(int width, int heigth, const char* windowName)
{
	this->gmWindow = glfwCreateWindow(width, heigth, windowName, NULL, NULL);
}

Window::~Window()
{
	delete this->gmWindow;
}

GLFWwindow* Window::GetGLFWwindow()
{
	return gmWindow;
}

void Window::MakeCurrent()
{
	glfwMakeContextCurrent(this->gmWindow);
}

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(this->gmWindow);
}

bool Window::IsWindowOpen()
{
	return this->gmWindow;
}
