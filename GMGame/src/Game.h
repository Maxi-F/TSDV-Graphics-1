#pragma once
#include <iostream>
#include "BaseGame.h"
#include "Shape.h"
#include "Square.h"
#include "Colors.h"

class Game : public GuichernoEngine::BaseGame
{
private:

public:
	GuichernoEngine::Shape* player;
	GuichernoEngine::Shape* enemy;

	Game();
	~Game();

	void Init();
	void DeInit();
	void Update();
};