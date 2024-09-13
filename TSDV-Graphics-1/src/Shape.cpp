#include "Shape.h"
#include "Renderer.h"


GuichernoEngine::Shape::Shape(float vertices[]) 
{
	Init(vertices, SHAPE_VERTEX_FLOAT_COUNT, SHAPE_VERTEX_COUNT);

	for (int i = 0; i < SHAPE_VERTEX_FLOAT_COUNT; i++)
	{
		this->vertices[i] = vertices[i];
	}
}

GuichernoEngine::Shape::~Shape()
{
}

void GuichernoEngine::Shape::Draw() 
{
	Renderer renderer;

	renderer.DrawElements(this->bufferData, this->model);
}

void GuichernoEngine::Shape::Update()
{
	// rotate the model once per second
	float angle = 0.0f;
	float speed = 0.5f;

	angle += speed * 1.0f;

	this->model = glm::rotate(this->model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
}
