#include "Shape.h"
#include "Renderer.h"
#include <iostream>
#include "ShaderType.h"

GuichernoEngine::Shape::Shape(float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType) : 
	Entity2D(vertices, vertexLength, arrayLength, shapeType)
{}

GuichernoEngine::Shape::~Shape()
{
}

void GuichernoEngine::Shape::Draw() 
{
	Renderer renderer;

	renderer.DrawElements(this->bufferData, this->model, this->color, ShaderType::Shape, 0);
}
