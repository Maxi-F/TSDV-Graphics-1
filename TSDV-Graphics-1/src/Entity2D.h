#pragma once
#include "Entity.h"
#include "ExportHeader.h"
#include "ShapeType.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Colors.h"
#include "Collider.h"

namespace GuichernoEngine
{
	class Entity2D : public Entity 
	{
		protected:
			glm::mat4 model = glm::mat4(1.0f);
			glm::vec3 translation = glm::vec3(0.0f);
			glm::vec3 scale = glm::vec3(1.0f);
			float rotationDegrees = 0.0f;
			Color color;
			Collider collider;

			void SetTRS();
			void ResetCollider();
			glm::vec4 GetPivot();
			unsigned int entityVertexCount;
			unsigned int entityVertexFloatCount;

		public:
			float* vertices;

			Entity2D(float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType);
			~Entity2D();

			GUICHERNO_API void Translate(float x, float y, float z);
			GUICHERNO_API void Rotate(float angle);
			GUICHERNO_API void Scale(float x, float y, float z);

			GUICHERNO_API void SetTranslate(float x, float y, float z);
			GUICHERNO_API void SetRotate(float angle);
			GUICHERNO_API void SetScale(float x, float y, float z);
			GUICHERNO_API void SetColor(Color color);
			GUICHERNO_API Collider GetCollider();
			GUICHERNO_API void SetCollider(Collider collider);
	};
}
