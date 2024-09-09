#pragma once
#include <GLEW/include/glew.h>
#include "Window.h"
#include "BufferPointer.h"

namespace GuichernoEngine
{	
	const int MAX_VERTEX_COUNT = 1024;
	const int MAX_INDEX_COUNT = 1024;

	class Renderer
	{

		private:
			static float vertices[MAX_VERTEX_COUNT];
			static float indices[MAX_INDEX_COUNT];
			static int vertexCount;
			static void GenerateShaders();

		public:
			static void Clear();
			static void SwapBuffers(Window window);
			static void GenerateBuffer();
			static void DrawArrays(BufferPointer pointer);
			static BufferPointer AddVertices(float verticesToAdd[], int count);
	};
}
