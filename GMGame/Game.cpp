#include "Game.h"
#include "ShapeType.h"
#include "Keys.h"
#include "CollisionManager.h"
#include "Sprite.h"
#include "GETime.h"

Game::Game() {
	this->knuckles = nullptr;
	this->rock = nullptr;
}

Game::~Game() {

}

void Game::Init()
{
	this->knuckles = GuichernoEngine::Sprite::FromRectangle(
		"images/Knuckles_Sprite_Sheet.png",
		{ 
			0.0f, 0.0f, 646.0f, 473.0f
		}, 
		GuichernoEngine::WHITE
	);

	this->rock = GuichernoEngine::Sprite::FromRectangle(
		"images/Rock.png",
		{
			500.0f, 200.0f, 244.0f, 207.0f
		},
		GuichernoEngine::WHITE
	);

	this->idleRockAnimation = new GuichernoEngine::Animation(
		{ 77, -20 },
		{ 79, 57, },
		{ this->rock->GetTextureWidth(), this->rock->GetTextureHeight() },
		1,
		100.0f
	);

	this->idleAnimation = new GuichernoEngine::Animation(
		{ 1, 1 },
		{ 36, 39, },
		{ this->knuckles->GetTextureWidth(), this->knuckles->GetTextureHeight() },
		1,
		100.0f
	);

	this->spinAnimation = new GuichernoEngine::Animation(
		{ 1, 127 },
		{ 32, 35, },
		{ this->knuckles->GetTextureWidth(), this->knuckles->GetTextureHeight() },
		4,
		0.8f
	);

	this->pushingRockAnimation = new GuichernoEngine::Animation(
		{ 420, 377 },
		{ 38, 40, },
		{ this->knuckles->GetTextureWidth(), this->knuckles->GetTextureHeight() },
		4,
		0.8f
	);

	this->walkAnimation = new GuichernoEngine::Animation(
		{ 1, 433 },
		{ 40, 40, },
		{ this->knuckles->GetTextureWidth(), this->knuckles->GetTextureHeight() },
		5,
		1.0f
	);

	this->knuckles->SetScale(100, 100, 0);
	this->knuckles->SetTranslate(100, 150, 0);
}

void Game::DeInit()
{
	delete this->knuckles;
	delete this->rock;
}

void Game::Update()
{
	this->knuckles->Update();

	this->rock->Draw();
	
	if(this->CheckCollision(this->knuckles, this->rock)) 
	{
		std::cout << "Collision detected" << std::endl;

		if (this->IsKeyPressed(GuichernoEngine::Keys::D))
		{
			this->knuckles->SetAnimation(this->pushingRockAnimation);
			this->knuckles->Translate(5, 0, 0);
			this->rock->Translate(5, 0, 0);
		}
		else if (this->IsKeyPressed(GuichernoEngine::Keys::A))
		{
			this->knuckles->SetAnimation(this->walkAnimation);
			this->knuckles->Translate(-10, 0, 0);
		}
		else
		{
			this->knuckles->SetAnimation(this->idleAnimation);
		}
	}
	else 
	{
		std::cout << "No collision detected" << std::endl;

		if (this->IsKeyPressed(GuichernoEngine::Keys::D))
		{
			this->knuckles->SetAnimation(this->walkAnimation);
			this->knuckles->Translate(10, 0, 0);
		}
		else if (this->IsKeyPressed(GuichernoEngine::Keys::L))
		{
			this->knuckles->SetAnimation(this->spinAnimation);
			this->knuckles->Translate(10, 0, 0);
		}
		else if (this->IsKeyPressed(GuichernoEngine::Keys::A))
		{
			this->knuckles->SetAnimation(this->walkAnimation);
			this->knuckles->Translate(-10, 0, 0);
		}
		else
		{
			this->knuckles->SetAnimation(this->idleAnimation);
		}
	}

	this->rock->SetAnimation(this->idleRockAnimation);

	this->knuckles->Draw();
}
