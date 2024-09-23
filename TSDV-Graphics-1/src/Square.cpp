#include "Square.h"

const unsigned int SQUARE_VERTEX_LENGTH = 7;
const unsigned int SQUARE_ARRAY_LENGTH = 28;

float* GuichernoEngine::Square::CreateSquareVertices(float x, float y, float width, float length, Color color)
{
	return new float[SQUARE_ARRAY_LENGTH] {
		// position                   // color
		x, y, 0.0f,					  color.r, color.g, color.b, color.a,
		x + width, y, 0.0f,			  color.r, color.g, color.b, color.a,
		x + width, y + length, 0.0f,  color.r, color.g, color.b, color.a,
		x, y + length, 0.0f,		  color.r, color.g, color.b, color.a
	};
}

GuichernoEngine::Square::Square(float x, float y, float width, float height, Color color) :
	Shape(
		CreateSquareVertices(x, y, width, height, color),
		SQUARE_VERTEX_LENGTH, SQUARE_ARRAY_LENGTH,
		ShapeType::SQUARE
	)
{}

GuichernoEngine::Square::~Square()
{
}
