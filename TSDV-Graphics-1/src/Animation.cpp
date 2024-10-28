#include "Animation.h"

GuichernoEngine::Animation::Animation(
	Sprite* sprite,
	Coords startCoords,
	int frameWidth,
	int frameHeight,
	int framesQuantity
)
{
	this->sprite = sprite;
	this->currentFrame = 0;

	float frameWidthFloat = static_cast<float>(frameWidth);
	float frameHeightFloat = static_cast<float>(frameHeight);
	float textureWidth = static_cast<float>(sprite->GetTextureWidth());
	float textureHeight = static_cast<float>(sprite->GetTextureHeight());

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

void GuichernoEngine::Animation::DrawFrame()
{
	// this->frames[this->currentFrame].Draw();
	this->sprite->SetUvCoords(
		this->frames[this->currentFrame].topLeftUVCoords,
		this->frames[this->currentFrame].bottomRightUVCoords
	);

	this->sprite->Draw();
}

void GuichernoEngine::Animation::NextFrame()
{
	this->currentFrame++;
	if(this->currentFrame >= this->frames.size())
	{
		this->currentFrame = 0;
	}
}
