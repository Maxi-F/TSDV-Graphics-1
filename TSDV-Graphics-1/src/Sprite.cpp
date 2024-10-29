#include "Sprite.h"
#include "ShaderType.h"
#include "Renderer.h"
#include "TextureImporter.h"

const unsigned int SQUARE_VERTEX_LENGTH = 9;
const unsigned int SQUARE_ARRAY_LENGTH = 36;

float* GuichernoEngine::Sprite::CreateSquareVertices()
{
	return new float[SQUARE_ARRAY_LENGTH] {
			// position          // color               // texture
		    0.5f, 0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
			0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
			-0.5f, 0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f // top left 
		};
}

GuichernoEngine::Sprite* GuichernoEngine::Sprite::FromRectangle(const char* filePath, RectangleData data, Color color)
{
	Sprite* sprite = new Sprite(filePath, CreateSquareVertices(), SQUARE_VERTEX_LENGTH, SQUARE_ARRAY_LENGTH, ShapeType::SQUARE);

	sprite->SetTranslate(data.x, data.y, 0.0f);
	sprite->SetScale(data.width, data.height, 1.0f);
	sprite->SetRotate(0.0f);
	sprite->SetColor(color);
	sprite->SetAnimation(nullptr);

	return sprite;
}

GuichernoEngine::Sprite* GuichernoEngine::Sprite::FromRectangle(const char* filePath, RectangleData data, Animation* animation, Color color)
{
	Sprite* sprite = new Sprite(filePath, CreateSquareVertices(), SQUARE_VERTEX_LENGTH, SQUARE_ARRAY_LENGTH, ShapeType::SQUARE);

	sprite->SetTranslate(data.x, data.y, 0.0f);
	sprite->SetScale(data.width, data.height, 1.0f);
	sprite->SetRotate(0.0f);
	sprite->SetColor(color);
	sprite->SetAnimation(animation);

	return sprite;
}

GuichernoEngine::Sprite::Sprite(const char* filePath, float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType) :
	Entity2D(vertices, vertexLength, arrayLength, shapeType)
{
	TextureImporter::Import(filePath, this->texture);
}

int GuichernoEngine::Sprite::GetTextureWidth()
{
	return this->texture.width;
}

int GuichernoEngine::Sprite::GetTextureHeight()
{
	return this->texture.height;
}

GuichernoEngine::Sprite::~Sprite()
{
}

void GuichernoEngine::Sprite::SetAnimation(Animation* anAnimation)
{
	this->animation = anAnimation;
}

void GuichernoEngine::Sprite::SetUvCoords(UvCoords topLeftUvCoords, UvCoords bottomRightUvCoords)
{
	const unsigned int FIRST_VERTEX_U = 7;
	const unsigned int FIRST_VERTEX_V = 8;

	const unsigned int SECOND_VERTEX_U = 16;
	const unsigned int SECOND_VERTEX_V = 17;

	const unsigned int THIRD_VERTEX_U = 25;
	const unsigned int THIRD_VERTEX_V = 26;

	const unsigned int FOURTH_VERTEX_U = 34;
	const unsigned int FOURTH_VERTEX_V = 35;

	this->bufferData.vertices[FIRST_VERTEX_U] = bottomRightUvCoords.u;
	this->bufferData.vertices[FIRST_VERTEX_V] = topLeftUvCoords.v;
	
	this->bufferData.vertices[SECOND_VERTEX_U] = bottomRightUvCoords.u;
	this->bufferData.vertices[SECOND_VERTEX_V] = bottomRightUvCoords.v;

	this->bufferData.vertices[THIRD_VERTEX_U] = topLeftUvCoords.u;
	this->bufferData.vertices[THIRD_VERTEX_V] = bottomRightUvCoords.v;

	this->bufferData.vertices[FOURTH_VERTEX_U] = topLeftUvCoords.u;
	this->bufferData.vertices[FOURTH_VERTEX_V] = topLeftUvCoords.v;
}

void GuichernoEngine::Sprite::Draw()
{
	if (this->animation) {
		Frame frame = this->animation->GetCurrentFrame();
		this->SetUvCoords(frame.topLeftUVCoords, frame.bottomRightUVCoords);
	}

	Renderer renderer;

	renderer.DrawElements(this->bufferData, this->model, this->color, ShaderType::Texture, this->texture.ID);
}
