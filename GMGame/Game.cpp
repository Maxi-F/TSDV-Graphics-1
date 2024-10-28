#include "Game.h"
#include "ShapeType.h"
#include "Keys.h"
#include "Sprite.h"

Game::Game() {
	this->player = nullptr;
	this->enemy = nullptr;
	this->sprite = nullptr;
}

Game::~Game() {

}

void Game::Init()
{
	this->player = new GuichernoEngine::Square({ 50.0f, 25.0f, 150.0f, 175.0f }, GuichernoEngine::RED);

	this->enemy = new GuichernoEngine::Triangle(250.0f, 250.0f, 150.0f, 175.0f, GuichernoEngine::RED);

	this->sprite = GuichernoEngine::Sprite::FromRectangle(
		"images/omori.png",
		{ 
			200.0f, 200.0f, 300.0f, 300.0f
		}, 
		GuichernoEngine::WHITE
	);

	this->idleAnimation = new GuichernoEngine::Animation(
		this->sprite,
		{ 34, 438 },
		31,
		31,
		1
	);

	this->walkAnimation = new GuichernoEngine::Animation(
		this->sprite,
		{ 1, 438 },
		31,
		31,
		3
	);
}

void Game::DeInit()
{
	delete this->player;
	delete this->enemy;
	delete this->sprite;
}

void Game::Update()
{
	if (this->IsKeyPressed(GuichernoEngine::Keys::W)) 
	{
		this->player->Rotate(4.0f);
	}
	this->player->Scale(0.01f, 1.0f, 1.0f);
	this->player->Translate(1.0f, 1.0f, 0.0f);

	this->player->Draw();
	this->enemy->Draw();
	
	// this->sprite->Draw();
	if(this->IsKeyPressed(GuichernoEngine::Keys::D)) 
	{
		this->walkAnimation->DrawFrame();
	}
	else 
	{
		this->idleAnimation->DrawFrame();
	}
}
