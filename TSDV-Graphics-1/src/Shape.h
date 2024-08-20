#pragma once
#include "Entity2D.h"
#include "BufferPointer.h"

namespace GuichernoEngine 
{
	static const int SHAPE_VERTEX_COUNT = 9;

	class Shape : Entity2D 
	{
		public:
			float vertices[SHAPE_VERTEX_COUNT];
			BufferPointer bufferPointer;

			Shape(float vertices[]);

			void Draw();
	};
}
