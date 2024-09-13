#pragma once
#include "Entity2D.h"
#include "ExportHeader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace GuichernoEngine 
{
	static const unsigned int SHAPE_VERTEX_FLOAT_COUNT = 9;
	static const unsigned int SHAPE_VERTEX_COUNT = 3;

	// For now this will be just triangles
	class Shape : public Entity2D 
	{
		private: 
			glm::mat4 model = glm::mat4(1.0f);

		public:
			float vertices[SHAPE_VERTEX_FLOAT_COUNT];

			GUICHERNO_API Shape(float vertices[]);
			GUICHERNO_API ~Shape();

			GUICHERNO_API void Draw();
			GUICHERNO_API void Update();
	};
}
