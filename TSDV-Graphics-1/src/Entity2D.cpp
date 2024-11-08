#include "Entity2D.h"
#include "Colors.h"
#include <iostream>

glm::vec4 GuichernoEngine::Entity2D::GetPivot()
{
	float sumX = 0.0f;
	float sumY = 0.0f;

	for (unsigned int i = 0; i < this->entityVertexFloatCount; i += this->entityVertexCount)
	{
		sumX += vertices[i];
		sumY += vertices[i + 1];
	}

	float xPivot = sumX / (this->entityVertexFloatCount / this->entityVertexCount);
	float yPivot = sumY / (this->entityVertexFloatCount / this->entityVertexCount);

	return
	{
		xPivot,
		yPivot,
		0.0f,
		1.0f
	};
}

void GuichernoEngine::Entity2D::SetTRS()
{
	this->model = glm::mat4(1.0f);
	this->model = glm::translate(this->model, this->translation);

	glm::vec4 pivot = GetPivot();

	this->model = glm::translate(this->model, glm::vec3(pivot.x, pivot.y, pivot.z));

	this->model = glm::rotate(this->model, glm::radians(this->rotationDegrees), glm::vec3(0.0f, 0.0f, 1.0f));
	this->model = glm::scale(this->model, this->scale);

	this->model = glm::translate(this->model, glm::vec3(-pivot.x, -pivot.y, -pivot.z));
}

GuichernoEngine::Entity2D::Entity2D(float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType)
{
	this->collider = { 0, 0, 0, 0 };
	this->color = WHITE;
	this->entityVertexFloatCount = arrayLength;
	this->entityVertexCount = vertexLength;
	this->vertices = new float[this->entityVertexFloatCount];

	Init(vertices, this->entityVertexFloatCount, this->entityVertexCount, shapeType);

	for (unsigned int i = 0; i < this->entityVertexFloatCount; i++)
	{
		this->vertices[i] = vertices[i];
	}

	delete[] vertices;
}

GuichernoEngine::Entity2D::~Entity2D()
{
	delete[] this->vertices;
}

void GuichernoEngine::Entity2D::Translate(float x, float y, float z)
{
	this->translation += glm::vec3(x, y, z);
	this->SetTRS();

	this->ResetCollider();
}

void GuichernoEngine::Entity2D::Rotate(float angle)
{
	this->rotationDegrees += angle;
	this->SetTRS();
}

void GuichernoEngine::Entity2D::Scale(float x, float y, float z)
{
	this->scale += glm::vec3(x, y, z);
	this->SetTRS();

	std::cout << "Scale: " << this->scale.x << ", " << this->scale.y << std::endl;

	this->ResetCollider();

}

void GuichernoEngine::Entity2D::SetTranslate(float x, float y, float z)
{
	this->translation = glm::vec3(x, y, z);
	this->SetTRS();

	this->collider = {
		x - (this->collider.width / 2.0f),
		y - (this->collider.height / 2.0f),
		this->collider.width,
		this->collider.height
	};

	this->ResetCollider();

}

void GuichernoEngine::Entity2D::ResetCollider()
{
	this->collider = {
		this->translation.x - (this->scale.x / 2.0f),
		this->translation.y - (this->scale.y / 2.0f),
		this->scale.x,
		this->scale.y
	};
}

void GuichernoEngine::Entity2D::SetRotate(float angle)
{
	this->rotationDegrees = angle;
	this->SetTRS();
}

void GuichernoEngine::Entity2D::SetScale(float x, float y, float z)
{
	this->scale = glm::vec3(x, y, z);
	this->SetTRS();

	this->ResetCollider();

}

void GuichernoEngine::Entity2D::SetColor(Color aColor)
{
	this->color = aColor;
}

GuichernoEngine::Collider GuichernoEngine::Entity2D::GetCollider()
{
	return this->collider;
}

void GuichernoEngine::Entity2D::SetCollider(Collider aCollider)
{
	this->collider = aCollider;
}
