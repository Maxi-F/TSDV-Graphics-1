#include "Sprite.h"
#include "ShaderType.h"
#include "Renderer.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

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
	/* TODO use texture importer */
	glGenTextures(1, &this->texture);
	glBindTexture(GL_TEXTURE_2D, this->texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the texture
	int width, height, nrChannels;
	unsigned char* data = stbi_load(filePath, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

GuichernoEngine::Sprite::~Sprite()
{
}

void GuichernoEngine::Sprite::Draw()
{
	Renderer renderer;

	renderer.DrawElements(this->bufferData, this->model, this->color, ShaderType::Texture, this->texture);
}
