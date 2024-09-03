#include "Game.h"

Game::Game() {
	this->player = nullptr;
}

Game::~Game() {

}

void Game::Init()
{
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	this->player = new GuichernoEngine::Shape(vertices);
}

void Game::DeInit()
{
	delete this->player;
}

void Game::Update()
{
	this->player->Draw();
}
