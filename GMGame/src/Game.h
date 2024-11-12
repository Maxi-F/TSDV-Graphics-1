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
	GuichernoEngine::Sprite* player;
	GuichernoEngine::Sprite* rock;
	GuichernoEngine::Sprite* background;
	GuichernoEngine::Square* square;
	GuichernoEngine::Animation* rockIdleAnimation;
	GuichernoEngine::Animation* idleAnimation;
	GuichernoEngine::Animation* runningAnimation;
	GuichernoEngine::Animation* spinningAnimation;
	GuichernoEngine::Animation* pushingAnimation;

	Game();
	~Game();

	void Init();
	void DeInit();
	void Update();
};