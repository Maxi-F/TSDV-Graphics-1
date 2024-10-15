#pragma once
#include "Shape.h"
#include "Colors.h"
#include "RectangleData.h"

namespace GuichernoEngine
{
	class Square : public Shape
	{
		private:
			static float* CreateSquareVertices();

		public:
			GUICHERNO_API Square(RectangleData data, Color color);
			GUICHERNO_API ~Square();
	};
}
