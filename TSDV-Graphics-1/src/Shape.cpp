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

	renderer.DrawElements(this->bufferData);
}
