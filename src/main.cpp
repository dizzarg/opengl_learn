#include <iostream>
#include <cstdio>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/vec4.hpp>

int main() {
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
    if (!window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading language version : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    glViewport(0, 0, 800, 600);

    const std::string vertexShaderString = R"(
        #version 460 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec3 aColor;

        out vec3 color;

        void main() {
            gl_Position  = vec4(aPos, 1.0);
            color = aColor;
        }
    )";

    const char *vertexShaderSrc = vertexShaderString.c_str();

    const GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSrc, nullptr);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    const std::string fragmentShaderString = R"(
        #version 460 core

        in vec3 color;
        out vec4 frag_color;

        void main() {
            frag_color = vec4(color, 1.0f);
        }
    )";
    const char *fragmentShaderSrc = fragmentShaderString.c_str();

    const GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSrc, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    const GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAMM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    constexpr float vertices[] = {
        -0.5, -0.5, 0,
        0.5, -0.5, 0,
        -0.5, 0.5, 0,

        0.5, -0.5, 0,
        0.5,  0.5, 0,
        -0.5, 0.5, 0,
    };

    constexpr float colors[] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1,

        0, 1, 0,
        1, 0, 0,
        0, 0, 1,
    };

    glm::vec4 vec4(1);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    GLuint vertexVBO;
    glGenBuffers(1, &vertexVBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindVertexArray(0);

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    GLuint colorVBO;
    glGenBuffers(1, &colorVBO);
    glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        float time = glfwGetTime();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        glUseProgram(program);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);

        glUseProgram(0);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            std::cout << "W key press" << std::endl;
        }
    }

    glDeleteProgram(program);
    glDeleteBuffers(1, &colorVBO);
    glDeleteBuffers(1, &vertexVBO);
    glDeleteVertexArrays(1, &VAO);

    glfwTerminate();
    return 0;
}
