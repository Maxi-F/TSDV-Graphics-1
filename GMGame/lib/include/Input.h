#pragma once
#include "ExportHeader.h"
#include "Window.h"
#include "Keys.h"

namespace GuichernoEngine
{
	class Input 
	{
		public:
			static void SetWindow(Window* window);
			GUICHERNO_API static bool IsKeyPressed(Keys key);

		private:
			static Window* window;
			static int GetGlfwKeyFromKey(Keys key);
	};
}
