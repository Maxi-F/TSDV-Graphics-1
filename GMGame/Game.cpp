#include "Game.h"
#include "ShapeType.h"
#include "Keys.h"
#include "CollisionManager.h"
#include "Sprite.h"
#include "GETime.h"

Game::Game() {
	this->player = nullptr;
	this->enemy = nullptr;
	this->sprite = nullptr;
}

Game::~Game() {

}

void Game::Init()
{
	// 320, 240

	// center this
	this->player = new GuichernoEngine::Square({
		320.0f, 240.0f, 100.0f, 100.0f
		}, GuichernoEngine::RED);

	this->enemy = new GuichernoEngine::Triangle(320.0f, 240.0f, 100.0f, 100.0f, GuichernoEngine::YELLOW);

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
		this->player->Rotate(4.0f * GuichernoEngine::GETime::deltaTime);
	}
	this->enemy->Rotate(20.0f * GuichernoEngine::GETime::deltaTime);
	this->enemy->Translate(0, -20.0f * GuichernoEngine::GETime::deltaTime, 0.0f);
	// this->enemy->Scale(20.0f * GuichernoEngine::GETime::deltaTime, 20.0f * GuichernoEngine::GETime::deltaTime, 1.0f);
	
	GuichernoEngine::Square({
		320.0f, 240.0f, 100.0f, 100.0f
		}, GuichernoEngine::BLUE).Draw();
	// this->player->Translate(0, -10.0f * GuichernoEngine::GETime::deltaTime, 0.0f);
	this->sprite->Update();

	// this->player->Draw();
	this->enemy->Draw();
	// this->library->Draw();
	

	if(GuichernoEngine::CollisionManager::CheckCollision(this->player, this->enemy)) 
	{
		std::cout << "Collision detected" << std::endl;
	}
	else {
		std::cout << "No collision detected" << std::endl;
	}


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
