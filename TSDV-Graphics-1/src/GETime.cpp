#include "GETime.h"
#include "Renderer.h"

float GuichernoEngine::GETime::lastTime = 0.0f;
float GuichernoEngine::GETime::deltaTime = 0.0f;

void GuichernoEngine::GETime::SetDeltaTime()
{
	Renderer* renderer;

	float actualTime = renderer->GetGlTime();

	GuichernoEngine::GETime::deltaTime = actualTime - lastTime;
	GuichernoEngine::GETime::lastTime = actualTime;
}
