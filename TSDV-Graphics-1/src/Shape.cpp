#include "Shape.h"
#include "Renderer.h"


GuichernoEngine::Shape::Shape(float vertices[]) 
{
	Renderer renderer;

	for (int i = 0; i < SHAPE_VERTEX_COUNT; i++)
	{
		this->vertices[i] = vertices[i];
	}

	this->bufferPointer = renderer.AddVertices(this->vertices, SHAPE_VERTEX_COUNT);
}

void GuichernoEngine::Shape::Draw() 
{
	Renderer renderer;

	renderer.DrawArrays(bufferPointer);
}
