#include "Animation.h"
#include "GETime.h"

GuichernoEngine::Animation::Animation(
	Coords startCoords,
	Area frameArea,
	Area textureArea,
	int framesQuantity,
	float animationTime
)
{
	this->currentFrame = 0;
	this->currentTime = 0.0f;
	this->animationTime = animationTime;

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
		UvCoords leftTopUVCoords =
		{
			startUVCoords.u + ((i * frameWidthFloat) / textureWidth),
			startUVCoords.v
		};

		UvCoords rightBottomUVCoords =
		{
			startUVCoords.u + frameWidthFloat / textureWidth + ((i * frameWidthFloat) / textureWidth),
			startUVCoords.v - (frameHeightFloat / textureHeight)
		};

		this->frames.push_back(Frame(leftTopUVCoords, rightBottomUVCoords));
	}

	this->frameTime = this->animationTime / static_cast<float>(this->frames.size());
}

GuichernoEngine::Animation::~Animation()
{
	frames.clear();
}

GuichernoEngine::Frame GuichernoEngine::Animation::GetCurrentFrame()
{
	return this->frames[this->currentFrame];
}

void GuichernoEngine::Animation::Update()
{
	this->currentTime += GETime::deltaTime;

	while (this->currentTime >= this->animationTime)
		this->currentTime -= this->animationTime;

	this->currentFrame = static_cast<int>(this->currentTime / this->frameTime);
}

void GuichernoEngine::Animation::NextFrame()
{
	this->currentFrame++;
	if (this->currentFrame >= this->frames.size())
	{
		this->currentFrame = 0;
	}
}

void GuichernoEngine::Animation::ResetTime()
{
	this->currentTime = 0;
}
