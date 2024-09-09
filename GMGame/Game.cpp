#include "Game.h"

Game::Game() {
	this->player = nullptr;
	this->enemy = nullptr;
}

Game::~Game() {

}

void Game::Init()
{
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f,  0.5f, 0.0f
	};

	this->player = new GuichernoEngine::Shape(vertices);

	float verticesEnemy[] = {
	0.5f, 0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f,
	-0.5f,  -0.5f, 0.0f
	};

	this->enemy = new GuichernoEngine::Shape(verticesEnemy);
}

void Game::DeInit()
{
	delete this->player;
	delete this->enemy;
}

void Game::Update()
{
	this->player->Draw();
	this->enemy->Draw();
}
