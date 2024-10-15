#pragma once
#include "Entity2D.h"

namespace GuichernoEngine 
{
	class Sprite : public Entity2D
	{
		public:
			unsigned int texture;
			GUICHERNO_API Sprite(float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType);
			GUICHERNO_API ~Sprite();

			GUICHERNO_API void Draw();
	};
}
