#include "Game.h"
#include "ShapeType.h"

Game::Game() 
{
	yellowTriangle = nullptr;
	pinkTriangle = nullptr;
}

Game::~Game() 
{
}

void Game::Init()
{
	yellowTriangle = new GuichernoEngine::Triangle(75.0f, 350.0f, 150.0f, 175.0f, GuichernoEngine::YELLOW);

	pinkTriangle = new GuichernoEngine::Triangle(560.0f, 75.0f, 150.0f, 175.0f, GuichernoEngine::MAGENTA);
}

void Game::DeInit()
{
	delete yellowTriangle;
	delete pinkTriangle;
}

void Game::Update()
{	
	yellowTriangle->Translate(0.0f, -1.0f, 0.0f);
	pinkTriangle->Translate(0.0f, 1.0f, 0.0f);

	yellowTriangle->Rotate(4.0f);
	pinkTriangle->Rotate(-4.0f);

	yellowTriangle->Draw();	
	pinkTriangle->Draw();
}
