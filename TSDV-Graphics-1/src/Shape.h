#pragma once
#include "Entity2D.h"
#include "ExportHeader.h"

namespace GuichernoEngine 
{
	static const unsigned int SHAPE_VERTEX_FLOAT_COUNT = 9;
	static const unsigned int SHAPE_VERTEX_COUNT = 3;

	// For now this will be just triangles
	class GUICHERNO_API Shape : public Entity2D 
	{
		public:
			float vertices[SHAPE_VERTEX_FLOAT_COUNT];

			Shape(float vertices[]);
			~Shape();

			void Draw();
	};
}
