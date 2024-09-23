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
	this->player = new GuichernoEngine::Square(50.0f, 25.0f, 150.0f, 175.0f, GuichernoEngine::RED);

	// TODO
	float* verticesEnemy = new float[21] {
		0.0f, 0.5f, 0.0f,  1.0f, 1.0f , 1.0f, 1.0f,
		0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f
	};

	this->enemy = new GuichernoEngine::Shape(verticesEnemy, 7, 21, GuichernoEngine::TRIANGLE);
}

void Game::DeInit()
{
	delete this->player;
	delete this->enemy;
}

void Game::Update()
{
	this->player->Rotate(4.0f);
	this->player->Scale(0.01f, 1.0f, 1.0f);
	this->player->Translate(1.0f, 1.0f, 0.0f);
	
	this->enemy->SetRotate(45.0f);
	this->enemy->SetScale(300.0f, 300.0f, 300.0f);

	this->player->Draw();
	this->enemy->Draw();
}
