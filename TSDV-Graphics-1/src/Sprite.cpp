#include "Sprite.h"
#include "ShaderType.h"
#include "Renderer.h"
#include "TextureImporter.h"

const unsigned int SQUARE_VERTEX_LENGTH = 9;
const unsigned int SQUARE_ARRAY_LENGTH = 36;

float* GuichernoEngine::Sprite::CreateSquareVertices()
{
	return new float[SQUARE_ARRAY_LENGTH] {
			// position         // color                // texture
			-0.5, -0.5, 0.0f,	1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			0.5, -0.5, 0.0f,	1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			0.5, 0.5, 0.0f,		1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			-0.5, 0.5, 0.0f,	1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
		};
}

GuichernoEngine::Sprite* GuichernoEngine::Sprite::FromRectangle(const char* filePath, RectangleData data, Color color)
{
	Sprite* sprite = new Sprite(filePath, CreateSquareVertices(), SQUARE_VERTEX_LENGTH, SQUARE_ARRAY_LENGTH, ShapeType::SQUARE);

	sprite->SetTranslate(data.x, data.y, 0.0f);
	sprite->SetScale(data.width, data.height, 1.0f);
	sprite->SetColor(color);

	return sprite;
}

GuichernoEngine::Sprite::Sprite(const char* filePath, float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType) :
	Entity2D(vertices, vertexLength, arrayLength, shapeType)
{
	TextureImporter::Import(filePath, this->texture);
}

GuichernoEngine::Sprite::~Sprite()
{
}

void GuichernoEngine::Sprite::Draw()
{
	Renderer renderer;

	renderer.DrawElements(this->bufferData, this->model, this->color, ShaderType::Texture, this->texture);
}
