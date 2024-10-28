#pragma once
#include <vector>
#include "ExportHeader.h"
#include "Sprite.h"
#include "Frame.h"
#include "Coords.h"

namespace GuichernoEngine
{
	class Animation
	{
		public:
			Sprite* sprite;
			std::vector<Frame> frames;
			unsigned int currentFrame;
			GUICHERNO_API Animation(Sprite* sprite, Coords startCoords, int frameWidth, int frameHeight, int framesQuantity);
			GUICHERNO_API ~Animation();

			GUICHERNO_API void DrawFrame();
			GUICHERNO_API void NextFrame();
	};
}
