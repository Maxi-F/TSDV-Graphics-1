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

	float xPivot = sumX / this->shapeVertexCount;
	float yPivot = sumY / this->shapeVertexCount;

	return 
	{ 
		xPivot, 
		yPivot, 
		0.0f 
	};
}

GuichernoEngine::Shape::Shape(float vertices[], unsigned int vertexLength, unsigned int arrayLength)
{
	this->shapeVertexFloatCount = arrayLength;
	this->shapeVertexCount = vertexLength;
	this->vertices = new float[this->shapeVertexFloatCount];

	Init(vertices, this->shapeVertexFloatCount, this->shapeVertexCount);

	for (unsigned int i = 0; i < this->shapeVertexFloatCount; i++)
	{
		this->vertices[i] = vertices[i];
	}
}

GuichernoEngine::Shape::~Shape()
{
		delete[] this->vertices;
}

void GuichernoEngine::Shape::Draw() 
{
	Renderer renderer;

	renderer.DrawElements(this->bufferData, this->model);
}

void GuichernoEngine::Shape::Update()
{
	glm::vec3 pivot = GetPivot();

	std::cout << pivot.x << " " << pivot.y << std::endl;
	this->model = glm::mat4(1.0f);
	this->model = glm::translate(this->model, pivot);
	this->model = glm::rotate(this->model, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
	this->model = glm::translate(this->model, -pivot);
}
