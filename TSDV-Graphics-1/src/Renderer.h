#pragma once
#include "Window.h"

namespace GuichernoEngine
{
	class Renderer
	{
		public:
			void Clear();
			void SwapBuffers(Window window);
	};
}