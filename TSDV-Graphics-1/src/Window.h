#pragma once
#include <GLFW/include/glfw3.h>

namespace GuichernoEngine
{
	class Window
	{
	private:
		GLFWwindow* gmWindow;

	public:
		Window(int width, int heigth, const char* windowName);

		GLFWwindow* GetGLFWwindow();
		void MakeCurrent();
		bool ShouldClose();
		bool IsWindowOpen();
	};
}

