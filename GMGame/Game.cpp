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
		100.0f, 50.0f, 0.0f,
		40.0f, 400.0f, 0.0f,
		20.0f, 300.0f, 0.0f
	};

	this->player = new GuichernoEngine::Shape(vertices);

	float verticesEnemy[] = {
		500.0f, 200.0f, 0.0f,
		500.0f, 300.0f, 0.0f,
		450.0f, 200.0f, 0.0f
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
	this->player->Update();
	this->player->Draw();
	this->enemy->Draw();
}
