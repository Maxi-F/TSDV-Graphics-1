#pragma once
#include <GLEW/include/glew.h>
#include "Window.h"

namespace GuichernoEngine
{
	class Renderer
	{
		public:
			void Clear();
			void SwapBuffers(Window window);
			void GenerateBuffer();
			void Draw();
	};
}