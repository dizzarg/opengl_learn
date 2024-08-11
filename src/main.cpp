#include <iostream>
#include <cstdio>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/vec4.hpp>

#include "Engine.h"

GLuint vertexShaderFromSource(const std::string& shaderString) {
    const char *shaderSrc = shaderString.c_str();
    const GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &shaderSrc, nullptr);
    glCompileShader(vertexShader);
    int success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return 0;
    }
    return vertexShader;
}

GLuint fragmentShaderFromSource(const std::string& shaderString) {
    int success;
    const char *shaderSrc = shaderString.c_str();
    const GLuint vertexShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertexShader, 1, &shaderSrc, nullptr);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        return 0;
    }
    return vertexShader;
}

GLuint createProgram(const GLuint vertexShader, const GLuint fragmentShader) {
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAMM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return program;
}

GLFWwindow * createWindow(const int width, const int height, const std::string &title) {
    /* Initialize the library */
    if (!glfwInit()) {

        std::cout << "Init error" << std::endl;
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow * window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading language version : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    GLint num;
    glGetIntegerv(GL_NUM_EXTENSIONS, &num);

    // std::cout << "Start" << std::endl;
    //
    // for (int i = 0; i < num; ++i) {
    //     std::cout<< glGetStringi(GL_EXTENSIONS, i) <<std::endl;
    // }
    // std::cout << "End" << std::endl;


    return window;
}

class Qaudro {

};

int main() {
    try {
        const auto engine = new Engine();
        engine->run();
        delete engine;
        return EXIT_SUCCESS;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}


int main1() {
    GLFWwindow * window = createWindow(800, 600, "Hello OpenGL");
    if (window == nullptr) {
        return EXIT_FAILURE;
    }

    const std::string vertexShaderString = R"glsl(
        #version 460 core
        layout (location = 0) in vec3 position;
        layout (location = 1) in vec3 color;

        out vec3 vertex_color;

        void main() {
            gl_Position  = vec4(position, 1.0);
            vertex_color = color;
        }
    )glsl";

    const std::string fragmentShaderString = R"glsl(
        #version 460 core

        in vec3 vertex_color;
        out vec4 frag_color;

        void main() {
            frag_color = vec4(vertex_color, 1.0f);
        }
    )glsl";

    const GLuint vertexShader = vertexShaderFromSource(vertexShaderString);
    const GLuint fragmentShader = fragmentShaderFromSource(fragmentShaderString);
    const GLuint program = createProgram(vertexShader, fragmentShader);

    constexpr float vertices[] = {
        -0.5, -0.5, 0,
        0.5, -0.5, 0,
        0.5, 0.5, 0,
        -0.5, 0.5, 0
    };

    constexpr float colors[] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1,
        0, 1, 0,
    };

    constexpr GLuint indices[] = {
        0, 1, 2,
        0, 2, 3
    };


    GLuint VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    GLuint vertexVBO;
    glGenBuffers(1, &vertexVBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    const GLint posAttrib = glGetAttribLocation(program, "position");
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(posAttrib);

    glBindVertexArray(0);

    glBindVertexArray(VAO);

    GLuint colorVBO;
    glGenBuffers(1, &colorVBO);
    glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    const GLint colorAttrib = glGetAttribLocation(program, "color");
    glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(colorAttrib);
    glBindVertexArray(0);

    glBindVertexArray(VAO);
    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        float time = glfwGetTime();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        glUseProgram(program);

        glBindVertexArray(VAO);
        // glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);

        glUseProgram(0);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
    }

    glDeleteProgram(program);
    glDeleteBuffers(1, &colorVBO);
    glDeleteBuffers(1, &vertexVBO);
    glDeleteVertexArrays(1, &VAO);

    glfwTerminate();
    return EXIT_SUCCESS;
}
