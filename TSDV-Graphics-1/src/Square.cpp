#include "Square.h"

const unsigned int SQUARE_VERTEX_LENGTH = 7;
const unsigned int SQUARE_ARRAY_LENGTH = 28;

float* GuichernoEngine::Square::CreateSquareVertices()
{
	return new float[SQUARE_ARRAY_LENGTH] {
		// position                   // color
		-0.5, -0.5, 0.0f,			  1.0f, 1.0f, 1.0f, 1.0f,
		0.5, -0.5, 0.0f,			  1.0f, 1.0f, 1.0f, 1.0f,
		0.5, 0.5, 0.0f,				  1.0f, 1.0f, 1.0f, 1.0f,
		-0.5, 0.5, 0.0f,		      1.0f, 1.0f, 1.0f, 1.0f
	};
}

GuichernoEngine::Square::Square(float x, float y, float width, float height, Color color) :
	Shape(
		CreateSquareVertices(),
		SQUARE_VERTEX_LENGTH, SQUARE_ARRAY_LENGTH,
		ShapeType::SQUARE
	)
{
	this->SetTranslate(x, y, 0.0f);
	this->SetScale(width, height, 1.0f);
	this->SetColor(color);
}

GuichernoEngine::Square::~Square()
{
}
