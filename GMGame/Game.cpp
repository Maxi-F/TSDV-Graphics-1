#include "Game.h"
#include "ShapeType.h"
#include "Keys.h"
#include "CollisionManager.h"
#include "Sprite.h"
#include "GETime.h"

Game::Game() {
	this->player = nullptr;
	this->rock = nullptr;
	this->rockIdleAnimation = nullptr;
	this->idleAnimation = nullptr;
	this->runningAnimation = nullptr;
	this->spinningAnimation = nullptr;
	this->pushingAnimation = nullptr;
}

Game::~Game() {

}

GuichernoEngine::RectangleData playerRectangle = {
	100.0f,
	180.0f,
	150.0f,
	150.0f
};

GuichernoEngine::RectangleData rockRectangle = {
	400.0f,
	180.0f,
	246.0f,
	171.0f
};

void Game::Init()
{
	this->player = GuichernoEngine::Sprite::FromRectangle(
		"images/Knuckles_Sprite_Sheet.png",
		playerRectangle,
		GuichernoEngine::WHITE
	);

	this->background = GuichernoEngine::Sprite::FromRectangle(
		"images/fondo.png",
		{ 320.0f, 240.0f, 640.0f, 480.0f },
		GuichernoEngine::WHITE
	);

	this->square = new GuichernoEngine::Square(playerRectangle, GuichernoEngine::WHITE);

	this->rock = GuichernoEngine::Sprite::FromRectangle(
		"images/Rock.jfif",
		rockRectangle,
		GuichernoEngine::WHITE
	);

	GuichernoEngine::Coords rockCoords = { 76, 187 };
	GuichernoEngine::Area rockArea = { 82, 57 };

	this->rockIdleAnimation = new GuichernoEngine::Animation(
		rockCoords,
		rockArea,
		{ this->rock->GetTextureWidth(), this->rock->GetTextureHeight() },
		1,
		1.0f // duration does not matter as it is 1 frame
	);

	// Set idle animation to set rock sprite
	this->rock->SetAnimation(this->rockIdleAnimation);

	GuichernoEngine::Coords idleCoords = { 1, 472 };
	GuichernoEngine::Area idleArea = { 36, 39 };

	this->idleAnimation = new GuichernoEngine::Animation(
		idleCoords,
		idleArea,
		{ this->player->GetTextureWidth(), this->player->GetTextureHeight() },
		1,
		1.0f // duration does not matter as it is 1 frame
	);

	GuichernoEngine::Coords spinningCoords = { 1, 342 };
	GuichernoEngine::Area spinningArea = { 32, 28 };

	this->spinningAnimation = new GuichernoEngine::Animation(
		spinningCoords,
		spinningArea,
		{ this->player->GetTextureWidth(), this->player->GetTextureHeight() },
		6,
		1.0f
	);

	GuichernoEngine::Coords runningCoords = { 340, 429 };
	GuichernoEngine::Area runningArea = { 40, 42 };

	this->runningAnimation = new GuichernoEngine::Animation(
		runningCoords,
		runningArea,
		{ this->player->GetTextureWidth(), this->player->GetTextureHeight() },
		4,
		0.5f
	);

	GuichernoEngine::Coords pushingCoords = { 426, 377 };
	GuichernoEngine::Area pushingArea = { 35, 36 };

	this->pushingAnimation = new GuichernoEngine::Animation(
		pushingCoords,
		pushingArea,
		{ this->player->GetTextureWidth(), this->player->GetTextureHeight() },
		4,
		0.5f
	);
}

void Game::DeInit()
{
	delete this->player;
	delete this->rock;
	delete this->background;
	delete this->rockIdleAnimation;
	delete this->idleAnimation;
	delete this->runningAnimation;
	delete this->spinningAnimation;
	delete this->pushingAnimation;
}

void Game::Update()
{
	bool isGoingRight = this->IsKeyPressed(GuichernoEngine::Keys::D);
	bool isGoingLeft = this->IsKeyPressed(GuichernoEngine::Keys::A);
	bool isSpinning = this->IsKeyPressed(GuichernoEngine::Keys::S);
	bool shouldDrawAABB = this->IsKeyPressed(GuichernoEngine::Keys::Q);

	float movingVelocity = 80.0f * GuichernoEngine::GETime::deltaTime;
	float movingRockVelocity = 40.0f * GuichernoEngine::GETime::deltaTime;

	if (isGoingRight) 
	{
		this->square->Translate(movingVelocity, 0.0f, 0.0f);
		this->player->Translate(movingVelocity, 0.0f, 0.0f);

		// Set scale as expected width and height, if it was modified because of going left
		this->player->SetScale(playerRectangle.width, playerRectangle.height, 1.0f);
		
		if (this->CheckCollision(this->player, this->rock))
		{
			this->player->Translate(-movingVelocity, 0.0f, 0.0f);
			this->square->Translate(-movingVelocity, 0.0f, 0.0f);
			this->player->Translate(movingRockVelocity, 0.0f, 0.0f);
			this->square->Translate(movingRockVelocity, 0.0f, 0.0f);
			this->player->SetAnimation(this->pushingAnimation);
			this->rock->Translate(movingRockVelocity, 0.0f, 0.0f);
		}
		else {
			this->player->SetAnimation(this->runningAnimation);
		}
	}
	else if (isGoingLeft) 
	{
		this->square->Translate(-movingVelocity, 0.0f, 0.0f);
		this->player->Translate(-movingVelocity, 0.0f, 0.0f);
		this->player->SetAnimation(this->runningAnimation);

		// Set scale as negative width to rotate the sprite
		this->player->SetScale(-playerRectangle.width, playerRectangle.height, 1.0f);
	}
	else if (isSpinning) 
	{
		this->player->SetAnimation(this->spinningAnimation);
	} else 
	{
		this->player->SetAnimation(this->idleAnimation);
	}

	this->background->Draw();
	if (shouldDrawAABB) {
		this->square->Draw();
	}
	this->player->Update();
	this->player->Draw();
	this->rock->Draw();
}
