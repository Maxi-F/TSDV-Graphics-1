#pragma once
#include <GLEW/include/glew.h>
#include "Window.h"
#include "BufferData.h"

namespace GuichernoEngine
{	
	class Renderer
	{

		private:
			static void GenerateShaders();
			static bool isSameVertex(float vertices[], float otherVertices[], unsigned int vertexIndex, unsigned int otherVertexIndex, unsigned int vertexFloatCount);
			static unsigned int* GenerateIndices(float vertices[], unsigned int vertexCount, unsigned int floatPerVertexCount, unsigned int& indexCount);

		public:
			static void Clear();
			static void SwapBuffers(Window window);
			static void SetMVP(glm::mat4 proj, glm::mat4 view, glm::mat4 model);
			static void Init(Window window);
			static BufferData GenerateBuffer(float vertices[], unsigned int vertexCount, unsigned int count);
			static void SetData(BufferData bufferData);
			static void DrawElements(BufferData bufferData, glm::mat4 model);
	};
}
