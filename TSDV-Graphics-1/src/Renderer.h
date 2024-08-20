#pragma once
#include <GLEW/include/glew.h>
#include "Window.h"
#include "BufferPointer.h"

namespace GuichernoEngine
{
	class Renderer
	{
		private:
			// TODO MAKE THIS VARIABLE
			static float vertices[500];
			static int vertexCount;

		public:
			static void Initialize();
			static void Clear();
			static void SwapBuffers(Window window);
			static void GenerateBuffer();
			static void DrawArrays(BufferPointer pointer);
			static BufferPointer AddVertices(float verticesToAdd[], int count);
	};
}
