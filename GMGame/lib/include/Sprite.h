#pragma once
#include "Entity2D.h"
#include "RectangleData.h"

namespace GuichernoEngine 
{
	class Sprite : public Entity2D
	{
		private:
			static float* CreateSquareVertices();

		public:
			unsigned int texture;
			GUICHERNO_API static Sprite* FromRectangle(const char* filePath, RectangleData data, Color color);
			GUICHERNO_API Sprite(const char* filePath, float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType);
			GUICHERNO_API ~Sprite();

			GUICHERNO_API void Draw();
	};
}
