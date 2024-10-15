#include "Game.h"
#include "ShapeType.h"
#include "Keys.h"
#include "Sprite.h"

Game::Game() {
	this->player = nullptr;
	this->enemy = nullptr;
}

Game::~Game() {

}

void Game::Init()
{
	this->player = new GuichernoEngine::Square(50.0f, 25.0f, 150.0f, 175.0f, GuichernoEngine::RED);

	this->enemy = new GuichernoEngine::Triangle(250.0f, 250.0f, 150.0f, 175.0f, GuichernoEngine::RED);

	// TODO handle this better
	float* vertices = new float[36] {
		// positions          // colors                 // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 0.0f,   0.0f, 1.0f    // top left 
	};

	this->sprite = new GuichernoEngine::Sprite(vertices, 9, 36, GuichernoEngine::ShapeType::SQUARE);
}

void Game::DeInit()
{
	delete this->player;
	delete this->enemy;
	delete this->sprite;
}

void Game::Update()
{
	if (this->IsKeyPressed(GuichernoEngine::Keys::W)) {
		this->player->Rotate(4.0f);
	}
	this->player->Scale(0.01f, 1.0f, 1.0f);
	this->player->Translate(1.0f, 1.0f, 0.0f);
	this->sprite->Scale(0.1f, 0.1f, 0.1f);

	this->sprite->Draw();
}
