#pragma once
#include <iostream>
#include "BaseGame.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "Sprite.h"
#include "Colors.h"
#include "Animation.h"

class Game : public GuichernoEngine::BaseGame
{
private:

public:
	GuichernoEngine::Sprite* knuckles;
	GuichernoEngine::Sprite* rock;
	GuichernoEngine::Animation* idleAnimation;
	GuichernoEngine::Animation* idleRockAnimation;
	GuichernoEngine::Animation* walkAnimation;
	GuichernoEngine::Animation* spinAnimation;
	GuichernoEngine::Animation* pushingRockAnimation;

	Game();
	~Game();

	void Init();
	void DeInit();
	void Update();
};