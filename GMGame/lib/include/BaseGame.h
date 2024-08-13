#pragma once
#ifdef GUICHERNO_EXPORTS
#define GUICHERNO_API __declspec(dllexport)
#else
#define GUICHERNO_API __declspec(dllimport)
#endif

class GUICHERNO_API BaseGame
{
	public:
		int run();
};