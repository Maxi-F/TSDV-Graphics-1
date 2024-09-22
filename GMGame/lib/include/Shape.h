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
			glm::mat4 model = glm::mat4(1.0f);
			glm::vec3 translation = glm::vec3(0.0f);
			glm::vec3 scale = glm::vec3(1.0f);
			float rotationDegrees = 0.0f;

			void SetTRS();
			glm::vec4 GetPivot();
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
