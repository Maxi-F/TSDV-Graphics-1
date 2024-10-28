#include "Frame.h"

GuichernoEngine::Frame::Frame(UvCoords topLeftUVCoords, UvCoords bottomRightUVCoords)
{
	this->topLeftUVCoords = topLeftUVCoords;
	this->bottomRightUVCoords = bottomRightUVCoords;
}

GuichernoEngine::Frame::~Frame()
{
}
