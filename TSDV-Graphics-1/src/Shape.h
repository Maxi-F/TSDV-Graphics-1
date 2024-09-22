#pragma once
#include "Entity2D.h"
#include "ExportHeader.h"
#include "ShapeType.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace GuichernoEngine 
{
	// For now this will be just triangles
	class Shape : public Entity2D 
	{
		private: 
			glm::mat4 translation = glm::mat4(1.0f);
			glm::mat4 rotation = glm::mat4(1.0f);
			glm::mat4 scale = glm::mat4(1.0f);

			glm::vec3 GetPivot();
			glm::mat4 GetTRS();
			unsigned int shapeVertexCount;
			unsigned int shapeVertexFloatCount;

		public:
			float *vertices;

			GUICHERNO_API Shape(float vertices[], unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType);
			GUICHERNO_API ~Shape();

			GUICHERNO_API void Translate(float x, float y, float z);
			GUICHERNO_API void Rotate(float angle);
			GUICHERNO_API void Scale(float x, float y, float z);

			GUICHERNO_API void Draw();
	};
}
