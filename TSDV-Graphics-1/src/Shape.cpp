#include "Shape.h"
#include "Renderer.h"
#include <iostream>
#include "ShaderType.h"

glm::vec4 GuichernoEngine::Shape::GetPivot()
{
	float sumX = 0.0f;
	float sumY = 0.0f;

	for (unsigned int i = 0; i < this->shapeVertexFloatCount; i += this->shapeVertexCount)
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
		0.0f,
		1.0f
	};
}

void GuichernoEngine::Shape::SetTRS()
{
	this->model = glm::mat4(1.0f);
	this->model = glm::translate(this->model, this->translation);
	
	glm::vec4 pivot = GetPivot();

	this->model = glm::translate(this->model, glm::vec3(pivot.x, pivot.y, pivot.z));

	this->model = glm::rotate(this->model, glm::radians(this->rotationDegrees), glm::vec3(0.0f, 0.0f, 1.0f));
	this->model = glm::scale(this->model, this->scale);

	this->model = glm::translate(this->model, glm::vec3(-pivot.x, -pivot.y, -pivot.z));
}

GuichernoEngine::Shape::Shape(float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType)
{
	this->shapeVertexFloatCount = arrayLength;
	this->shapeVertexCount = vertexLength;
	this->vertices = new float[this->shapeVertexFloatCount];

	Init(vertices, this->shapeVertexFloatCount, this->shapeVertexCount, shapeType);

	for (unsigned int i = 0; i < this->shapeVertexFloatCount; i++)
	{
		this->vertices[i] = vertices[i];
	}

	delete[] vertices;
}

GuichernoEngine::Shape::~Shape()
{
		delete[] this->vertices;
}

void GuichernoEngine::Shape::Translate(float x, float y, float z)
{
	this->translation += glm::vec3(x, y, z);
	this->SetTRS();
}

void GuichernoEngine::Shape::Rotate(float angle)
{
	this->rotationDegrees += angle;
	this->SetTRS();
}

void GuichernoEngine::Shape::Scale(float x, float y, float z)
{
	this->scale += glm::vec3(x, y, z);
	this->SetTRS();
}

void GuichernoEngine::Shape::SetTranslate(float x, float y, float z)
{
	this->translation = glm::vec3(x, y, z);
	this->SetTRS();
}

void GuichernoEngine::Shape::SetRotate(float angle)
{
	this->rotationDegrees = angle;
	this->SetTRS();
}

void GuichernoEngine::Shape::SetScale(float x, float y, float z)
{
	this->scale = glm::vec3(x, y, z);
	this->SetTRS();
}

void GuichernoEngine::Shape::SetColor(Color aColor)
{
	this->color = aColor;
}

void GuichernoEngine::Shape::Draw() 
{
	Renderer renderer;

	renderer.DrawElements(this->bufferData, this->model, this->color, ShaderType::Shape);
}
