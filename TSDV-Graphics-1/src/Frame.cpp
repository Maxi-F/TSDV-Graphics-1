#include "Frame.h"

GuichernoEngine::Frame::Frame(UvCoords topLeftUVCoords, UvCoords bottomRightUVCoords)
{
	this->leftTopUVCoords = topLeftUVCoords;
	this->rightBottomUvCoords = bottomRightUVCoords;
}

GuichernoEngine::Frame::~Frame()
{
}
