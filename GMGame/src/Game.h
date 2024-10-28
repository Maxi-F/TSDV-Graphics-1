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
	GuichernoEngine::Square* player;
	GuichernoEngine::Triangle* enemy;
	GuichernoEngine::Sprite* sprite;
	GuichernoEngine::Animation* idleAnimation;
	GuichernoEngine::Animation* walkAnimation;

	Game();
	~Game();

	void Init();
	void DeInit();
	void Update();
};