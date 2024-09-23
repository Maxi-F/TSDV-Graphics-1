#pragma once
#include "Shape.h"
#include "Colors.h"

namespace GuichernoEngine
{
	class Triangle : public Shape
	{
	private:
		static float* CreateTriangleVertices();

	public:
		GUICHERNO_API Triangle(float x, float y, float baseLength, float height, Color color);
		GUICHERNO_API ~Triangle();
	};
}