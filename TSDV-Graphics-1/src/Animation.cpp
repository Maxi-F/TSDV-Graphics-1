#include "Animation.h"

GuichernoEngine::Animation::Animation(
	Coords startCoords,
	Area frameArea,
	Area textureArea,
	int framesQuantity
)
{
	this->currentFrame = 0;

	float frameWidthFloat = static_cast<float>(frameArea.width);
	float frameHeightFloat = static_cast<float>(frameArea.height);
	float textureWidth = static_cast<float>(textureArea.width);
	float textureHeight = static_cast<float>(textureArea.height);

	UvCoords startUVCoords = {
		startCoords.x / textureWidth,
		startCoords.y / textureHeight
	};



	for (int i = 0; i < framesQuantity; i++)
	{
		UvCoords topLeftUVCoords =
		{
			startUVCoords.u + ((i * frameWidthFloat) / textureWidth),
			startUVCoords.v
		};

		UvCoords bottomRightUVCoords =
		{
			topLeftUVCoords.u + ((frameWidthFloat + (i * frameWidthFloat)) / textureWidth),
			topLeftUVCoords.v - (frameHeightFloat / textureHeight)
		};

		this->frames.push_back(Frame(topLeftUVCoords, bottomRightUVCoords));
	}
}

GuichernoEngine::Animation::~Animation()
{
	frames.clear();
}

GuichernoEngine::Frame GuichernoEngine::Animation::GetCurrentFrame()
{
	return this->frames[this->currentFrame];
}

void GuichernoEngine::Animation::NextFrame()
{
	this->currentFrame++;
	if(this->currentFrame >= this->frames.size())
	{
		this->currentFrame = 0;
	}
}
