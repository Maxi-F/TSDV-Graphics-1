#include "Game.h"

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
		50.0f, 25.0f, 0.0f,
		200.0f, 200.0f, 0.0f,
		200.0f, 25.0f, 0.0f,
	};

	this->player = new GuichernoEngine::Shape(vertices, 3, 9);

	float verticesEnemy[] = 
	{
		50.0f, 25.0f, 0.0f,
		200.0f, 200.0f, 0.0f,
		50.0f, 200.0f, 0.0f
	};

	this->enemy = new GuichernoEngine::Shape(verticesEnemy, 3, 9);
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
