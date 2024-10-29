#pragma once
#include <vector>
#include "ExportHeader.h"
#include "Frame.h"
#include "Coords.h"
#include "Area.h"

namespace GuichernoEngine
{
	class Animation
	{
		public:
			std::vector<Frame> frames;
			unsigned int currentFrame;
			GUICHERNO_API Animation(Coords startCoords, Area frameArea, Area textureArea, int framesQuantity);
			GUICHERNO_API ~Animation();
			Frame GetCurrentFrame();

			GUICHERNO_API void NextFrame();
	};
}
