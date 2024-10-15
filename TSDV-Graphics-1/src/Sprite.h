#pragma once
#include "Entity2D.h"

namespace GuichernoEngine 
{
	class GUICHERNO_API Sprite : public Entity2D
	{
		public:
			Sprite(float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType);
			~Sprite();

			void Draw();
	};
}
