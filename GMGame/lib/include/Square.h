#pragma once
#include "Shape.h"
#include "Colors.h"

namespace GuichernoEngine
{
	class Square : public Shape
	{
		private:
			static float* CreateSquareVertices(Color color);

		public:
			GUICHERNO_API Square(float x, float y, float width, float length, Color color);
			GUICHERNO_API ~Square();
	};
}
