#include <iostream>
#include <cstdio>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "Init error" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    auto const window = glfwCreateWindow(800, 600, "Hello World", nullptr, nullptr);
    if (!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    std::cout << "Vendor: " << glGetString(GL_VENDOR) <<std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) <<std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) <<std::endl;
    std::cout << "Shading language version : " << glGetString(GL_SHADING_LANGUAGE_VERSION) <<std::endl;

    glViewport(0, 0, 800, 600);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        float time = glfwGetTime();
        glClearColor(abs(sin(time)), abs(cos(time)), abs(sin(time + 3.14f/4.0f)), 1.0);



        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}