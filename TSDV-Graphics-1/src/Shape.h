#pragma once
#include "Entity2D.h"
#include "BufferPointer.h"
#include "ExportHeader.h"

namespace GuichernoEngine 
{
	static const unsigned int SHAPE_VERTEX_COUNT = 9;

	class GUICHERNO_API Shape : public Entity2D 
	{
		public:
			float vertices[SHAPE_VERTEX_COUNT];
			BufferPointer bufferPointer;

			Shape(float vertices[]);

			void Draw();
	};
}
