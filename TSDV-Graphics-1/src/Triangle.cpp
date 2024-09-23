#include "Triangle.h"

const unsigned int TRIANGLE_VERTEX_LENGTH = 7;
const unsigned int TRIANGLE_ARRAY_LENGTH = 21;

float* GuichernoEngine::Triangle::CreateTriangleVertices(Color color)
{
	return new float[TRIANGLE_ARRAY_LENGTH] {
		// position                 // color
		-0.5f, -0.5f, 0.0f,		color.r, color.g, color.b, color.a,  // bottom left
		0.5f, -0.5f, 0.0f,		color.r, color.g, color.b, color.a,  // bottom right
		0.0f, 0.5f, 0.0f,		color.r, color.g, color.b, color.a   // top
	};
}

GuichernoEngine::Triangle::Triangle(float x, float y, float baseLength, float height, Color color) :
	Shape(
		CreateTriangleVertices(color),
		TRIANGLE_VERTEX_LENGTH, TRIANGLE_ARRAY_LENGTH,
		ShapeType::TRIANGLE
	)
{
	this->SetTranslate(x, y, 0.0f);
	this->SetScale(baseLength, height, 1.0f);
}

GuichernoEngine::Triangle::~Triangle()
{
}