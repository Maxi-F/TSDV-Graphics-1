#pragma once
#include <iostream>
#include "BaseGame.h"
#include "Shape.h"

class Game : public GuichernoEngine::BaseGame
{
private:

public:
	GuichernoEngine::Shape* player;

	Game();
	~Game();

	void Init();
	void DeInit();
	void Update();
};