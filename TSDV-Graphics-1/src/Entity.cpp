#include "Entity.h"
#include "Renderer.h"

void GuichernoEngine::Entity::Init(float vertices[], unsigned int vertexCount, unsigned int count, ShapeType shapeType)
{
	Renderer renderer;

	this->bufferData = renderer.GenerateBuffer(vertices, vertexCount, count, shapeType);
}

GuichernoEngine::Entity::~Entity()
{
	delete[] this->bufferData.indices;
	delete[] this->bufferData.vertices;

	this->bufferData.indices = nullptr;
	this->bufferData.vertices = nullptr;
}
