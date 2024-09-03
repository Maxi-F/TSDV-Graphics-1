#include "BaseGame.h"
#include "Window.h"
#include "Renderer.h"
#include <iostream>

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

    Init();
    
    std::cout << "After init game" << std::endl;

    gmRenderer->GenerateBuffer();

    StartGame();

    return 0;
}

int GuichernoEngine::BaseGame::StartGame()
{
    std::cout << "Start game" << std::endl;

    /* Loop until the user closes the window */
    while (!gmWindow->ShouldClose())
    {
        std::cout << "In loop" << std::endl;

        /* Render here */
        gmRenderer->Clear();
        
        std::cout << "clear render" << std::endl;

        Update();

        std::cout << "update game" << std::endl;

        /* Swap front and back buffers */
        gmRenderer->SwapBuffers(*gmWindow);

        std::cout << "swap buffers" << std::endl;

        /* Poll for and process events */

        glfwPollEvents();
        std::cout << "poll" << std::endl;

    }

    DeInit();

    glfwTerminate();
    delete gmWindow;
    delete gmRenderer;

    return 0;
}

