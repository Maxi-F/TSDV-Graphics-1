#pragma once
#include "ExportHeader.h"

namespace GuichernoEngine
{
	class BaseGame
	{
	public:
		GUICHERNO_API BaseGame();
		GUICHERNO_API ~BaseGame();

		int GUICHERNO_API StartEngine();
		int GUICHERNO_API StartGame();

		virtual void GUICHERNO_API Init() = 0;
		virtual void GUICHERNO_API DeInit() = 0;
		virtual void GUICHERNO_API Update() = 0;
	};
}
