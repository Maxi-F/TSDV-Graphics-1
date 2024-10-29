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
		private:
			float currentTime;
			float animationTime;

		public:
			std::vector<Frame> frames;
			unsigned int currentFrame;

			GUICHERNO_API Animation(Coords startCoords, Area frameArea, Area textureArea, int framesQuantity, float animationTime);
			GUICHERNO_API ~Animation();
			GUICHERNO_API void Update();
			GUICHERNO_API void NextFrame();
			void ResetTime();
			
			Frame GetCurrentFrame();
	};
}
