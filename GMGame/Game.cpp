#include "Game.h"
#include "ShapeType.h"

const float TRIANGLE_WIDTH = 50.0f;
const float TRIANGLE_HEIGHT = 50.0f;
const float WINDOW_WIDTH = 640.0f;
const float WINDOW_HEIGHT = 480.0f;

Game::Game() {
	this->firstTriangle = nullptr;
	this->secondTriangle = nullptr;
}

Game::~Game() {

}

void Game::Init()
{
	this->firstTriangle = new GuichernoEngine::Triangle(
		TRIANGLE_WIDTH / 2.0f,
		WINDOW_HEIGHT - TRIANGLE_HEIGHT / 2.0f,
		TRIANGLE_WIDTH,
		TRIANGLE_HEIGHT,
		GuichernoEngine::YELLOW
	);

	GuichernoEngine::Color pink = { 1.0f, 0.5f, 0.5f };

	this->secondTriangle = new GuichernoEngine::Triangle(
		WINDOW_WIDTH - TRIANGLE_WIDTH / 2.0f,
		TRIANGLE_HEIGHT / 2.0f,
		TRIANGLE_WIDTH,
		TRIANGLE_HEIGHT,
		pink
	);
}

void Game::DeInit()
{
	delete this->firstTriangle;
	delete this->secondTriangle;
}

void Game::Update()
{
	this->firstTriangle->Translate(0.0f, -1.0f, 0.0f);
	this->secondTriangle->Translate(0.0f, 1.0f, 0.0f);

	this->firstTriangle->Rotate(-1.0f);
	this->secondTriangle->Rotate(1.0f);

	this->firstTriangle->Draw();
	this->secondTriangle->Draw();
}
