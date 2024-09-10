#include "Entity.h"

void GuichernoEngine::Entity::Init(float vertices[], unsigned int vertexCount, unsigned int count)
{
	Renderer renderer;

	this->bufferData = renderer.GenerateBuffer(vertices, vertexCount, count);
}
