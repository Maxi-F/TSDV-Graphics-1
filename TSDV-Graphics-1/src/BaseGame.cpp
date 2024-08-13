#include <GLFW/include/glfw3.h>
#include "BaseGame.h"
#include "Window.h"

int BaseGame::run()
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    Window gmWindow = Window(640, 480, "Hello World");

    if (!gmWindow.IsWindowOpen())
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    gmWindow.MakeCurrent();

    /* Loop until the user closes the window */
    while (!gmWindow.ShouldClose())
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(gmWindow.GetGLFWwindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}