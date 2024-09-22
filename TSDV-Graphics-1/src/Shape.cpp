#include "Shape.h"
#include "Renderer.h"
#include <iostream>

glm::vec3 GuichernoEngine::Shape::GetPivot()
{
	float sumX = 0.0f;
	float sumY = 0.0f;

	for(unsigned int i = 0; i < this->shapeVertexFloatCount; i += this->shapeVertexCount)
	{
		sumX += vertices[i];
		sumY += vertices[i + 1];
	}

	float xPivot = sumX / (this->shapeVertexFloatCount / this->shapeVertexCount);
	float yPivot = sumY / (this->shapeVertexFloatCount / this->shapeVertexCount);

	return 
	{ 
		xPivot, 
		yPivot, 
		0.0f 
	};
}

glm::mat4 GuichernoEngine::Shape::GetTRS()
{
	return this->scale * this->rotation * this->translation;
}

GuichernoEngine::Shape::Shape(float vertices[], unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType)
{
	this->shapeVertexFloatCount = arrayLength;
	this->shapeVertexCount = vertexLength;
	this->vertices = new float[this->shapeVertexFloatCount];

	Init(vertices, this->shapeVertexFloatCount, this->shapeVertexCount, shapeType);

	for (unsigned int i = 0; i < this->shapeVertexFloatCount; i++)
	{
		this->vertices[i] = vertices[i];
	}
}

GuichernoEngine::Shape::~Shape()
{
		delete[] this->vertices;
}

void GuichernoEngine::Shape::Translate(float x, float y, float z)
{
	this->translation = glm::translate(this->translation, glm::vec3(x, y, z));
}

void GuichernoEngine::Shape::Rotate(float angle)
{
	glm::vec3 pivot = GetPivot();

	this->rotation = glm::translate(this->translation, pivot);
	this->rotation = glm::rotate(this->rotation, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
	this->rotation = glm::translate(this->translation, -pivot);
}

void GuichernoEngine::Shape::Scale(float x, float y, float z)
{
	this->scale = glm::scale(this->scale, glm::vec3(x, y, z));
}

void GuichernoEngine::Shape::Draw() 
{
	Renderer renderer;

	renderer.DrawElements(this->bufferData, this->GetTRS());
}
