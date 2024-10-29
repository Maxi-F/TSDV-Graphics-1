#pragma once
#include "ExportHeader.h"

namespace GuichernoEngine
{
	class GUICHERNO_API GETime
	{
		public:
			static float lastTime;
			static float deltaTime;

			static void SetDeltaTime();
	};
}
