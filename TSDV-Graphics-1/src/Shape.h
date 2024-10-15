#pragma once
#include "Entity2D.h"
#include "ExportHeader.h"
#include "ShapeType.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Colors.h"

namespace GuichernoEngine 
{
	class Shape : public Entity2D 
	{		
		public:
			GUICHERNO_API Shape(float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType);
			GUICHERNO_API ~Shape();

			GUICHERNO_API void Draw();
	};
}
