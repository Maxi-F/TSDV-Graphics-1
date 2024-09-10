#pragma once
#include <GLEW/include/glew.h>
#include "Window.h"
#include "BufferPointer.h"
#include "BufferData.h"

namespace GuichernoEngine
{	
	class Renderer
	{

		private:
			static void GenerateShaders();
			static int isSameVertex(float vertices[], float otherVertices[], unsigned int vertexIndex, unsigned int otherVertexIndex, unsigned int vertexFloatCount);
			static unsigned int* GenerateIndices(float vertices[], unsigned int vertexCount, unsigned int floatPerVertexCount, unsigned int& indexCount);

		public:
			static void Clear();
			static void SwapBuffers(Window window);
			static BufferData GenerateBuffer(float vertices[], unsigned int vertexCount, unsigned int count);
			static void DrawArrays(BufferPointer pointer);
			static BufferPointer AddVertices(float verticesToAdd[], unsigned int count);
	};
}
