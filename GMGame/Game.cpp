#include "Game.h"
#include "ShapeType.h"

Game::Game() {
	this->player = nullptr;
	this->enemy = nullptr;
}

Game::~Game() {

}

void Game::Init()
{
	float vertices[] = 
	{
		50.0f, 25.0f, 0.0f, // abajo izquierda
		200.0f, 25.0f, 0.0f, // abajo derecha
		200.0f, 200.0f, 0.0f, // arriba derecha
		50.0f, 200.0f, 0.0f // arriba izquierda
	};

	this->player = new GuichernoEngine::Shape(vertices, 3, 12, GuichernoEngine::SQUARE);

	float verticesEnemy[] = 
	{
		300.0f, 300.0f, 0.0f,
		350.0f, 400.0f, 0.0f,
		450.0f, 500.0f, 0.0f
	};

	this->enemy = new GuichernoEngine::Shape(verticesEnemy, 3, 9, GuichernoEngine::TRIANGLE);
}

void Game::DeInit()
{
	delete this->player;
	delete this->enemy;
}

void Game::Update()
{
	this->player->Update();
	this->enemy->Update();
	this->player->Draw();
	this->enemy->Draw();
}
