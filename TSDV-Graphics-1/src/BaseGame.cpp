#include "BaseGame.h"
#include "Window.h"
#include "Renderer.h"
#include "Shape.h"

using namespace GuichernoEngine;

int BaseGame::run()
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    Window gmWindow = Window(640, 480, "Hello World");
    Renderer renderer;

    if (!gmWindow.IsWindowOpen())
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    gmWindow.MakeCurrent();

    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

    Shape triangle = Shape(vertices);
    Shape triangle2 = Shape(vertices);

    renderer.GenerateBuffer();

    /* Loop until the user closes the window */
    while (!gmWindow.ShouldClose())
    {
        /* Render here */
        renderer.Clear();

        triangle.Draw();
        triangle2.Draw();

        /* Swap front and back buffers */
        renderer.SwapBuffers(gmWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}