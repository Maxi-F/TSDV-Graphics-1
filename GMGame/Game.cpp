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

	this->enemy = new GuichernoEngine::Triangle(200.0f, 50.0f, 800.0f, 800.0f, GuichernoEngine::RED);

	this->sprite = GuichernoEngine::Sprite::FromRectangle(
		"images/omori.png",
		{ 
			200.0f, 200.0f, 300.0f, 300.0f
		}, 
		GuichernoEngine::WHITE
	);

	this->library = GuichernoEngine::Sprite::FromRectangle(
		"images/container.jpg",
		{
			200.0f, 200.0f, 300.0f, 300.0f
		},
		GuichernoEngine::WHITE
	);

	this->idleAnimation = new GuichernoEngine::Animation(
		{ 34, 438 },
		{ 33, 32, },
		{ this->sprite->GetTextureWidth(), this->sprite->GetTextureHeight() },
		1,
		100.0f
	);

	this->walkAnimation = new GuichernoEngine::Animation(
		{ 1, 438 },
		{ 33, 32, },
		{ this->sprite->GetTextureWidth(), this->sprite->GetTextureHeight() },
		3,
		0.8f
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
	this->sprite->Update();

	this->player->Draw();
	this->enemy->Draw();
	this->library->Draw();
	

	if(this->IsKeyPressed(GuichernoEngine::Keys::D)) 
	{
		this->sprite->SetAnimation(this->walkAnimation);
	}
	else 
	{
		this->sprite->SetAnimation(this->idleAnimation);
	}

	this->sprite->Draw();
}
