#pragma once
#include "Entity2D.h"
#include "ExportHeader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace GuichernoEngine 
{
	// For now this will be just triangles
	class Shape : public Entity2D 
	{
		private: 
			glm::mat4 model = glm::mat4(1.0f);
			glm::vec3 GetPivot();
			unsigned int shapeVertexCount;
			unsigned int shapeVertexFloatCount;

		public:
			float *vertices;

			GUICHERNO_API Shape(float vertices[], unsigned int vertexLength, unsigned int arrayLength);
			GUICHERNO_API ~Shape();

			GUICHERNO_API void Draw();
			GUICHERNO_API void Update();
	};
}
