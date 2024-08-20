#include "BaseGame.h"
#include "Window.h"
#include "Renderer.h"

using namespace GuichernoEngine;

int BaseGame::run()
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    Window gmWindow = Window(640, 480, "Hello World");
    Renderer renderer = Renderer();

    if (!gmWindow.IsWindowOpen())
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    gmWindow.MakeCurrent();

    renderer.GenerateBuffer();

    /* Loop until the user closes the window */
    while (!gmWindow.ShouldClose())
    {
        /* Render here */
        renderer.Clear();

        renderer.Draw();

        /* Swap front and back buffers */
        renderer.SwapBuffers(gmWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}