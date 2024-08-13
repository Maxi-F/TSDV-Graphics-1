#pragma once
#include <GLFW/include/glfw3.h>

class Window
{
private:
	GLFWwindow* gmWindow;

public:
	Window(int width, int heigth, const char* windowName);
	~Window();

	GLFWwindow* GetGLFWwindow();
	void MakeCurrent();
	bool ShouldClose();
	bool IsWindowOpen();
};