#include <iostream>

#include "GETime.h"
#include "BaseGame.h"
#include "Window.h"
#include "Renderer.h"
#include "Input.h"

using namespace GuichernoEngine;

Window* gmWindow;
Renderer* gmRenderer;

GuichernoEngine::BaseGame::BaseGame()
{
    gmWindow = nullptr;
    gmRenderer = nullptr;
}

GuichernoEngine::BaseGame::~BaseGame()
{
}

int BaseGame::StartEngine()
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    gmWindow = new Window(640, 480, "GM");

    if (!gmWindow->IsWindowOpen())
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    gmWindow->MakeCurrent();

    GuichernoEngine::Input::SetWindow(gmWindow);
    gmRenderer->Init(*gmWindow);

    Init();
    
    std::cout << "After init game" << std::endl;

    StartGame();

    return 0;
}

int GuichernoEngine::BaseGame::StartGame()
{
    std::cout << "Start game" << std::endl;

    /* Loop until the user closes the window */
    while (!gmWindow->ShouldClose())
    {
        GETime::SetDeltaTime();

        /* Render here */
        gmRenderer->Clear();
        
        Update();

        /* Swap front and back buffers */
        gmRenderer->SwapBuffers(*gmWindow);

        /* Poll for and process events */

        glfwPollEvents();
    }

    DeInit();

    glfwTerminate();
    delete gmWindow;
    delete gmRenderer;

    return 0;
}

bool GuichernoEngine::BaseGame::IsKeyPressed(Keys key)
{
    return GuichernoEngine::Input::IsKeyPressed(key);
}

