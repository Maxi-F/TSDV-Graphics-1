#pragma once
#include <GLEW/include/glew.h>
#include <GLFW/include/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace GuichernoEngine
{
	class Window
	{
	private:
		GLFWwindow* gmWindow;
		glm::mat4 projection;

	public:
		Window();
		Window(int width, int heigth, const char* windowName);

		GLFWwindow* GetGLFWwindow();
		glm::mat4 GetProjection();
		void MakeCurrent();
		bool ShouldClose();
		bool IsWindowOpen();
	};
}

