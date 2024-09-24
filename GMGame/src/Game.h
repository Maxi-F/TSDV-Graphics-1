#pragma once
#include <iostream>
#include "BaseGame.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "Colors.h"

class Game : public GuichernoEngine::BaseGame
{
private:

public:
	GuichernoEngine::Triangle* firstTriangle;
	GuichernoEngine::Triangle* secondTriangle;

	Game();
	~Game();

	void Init();
	void DeInit();
	void Update();
};