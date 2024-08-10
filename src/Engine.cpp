//
// Created by dkadyrov on 10.08.2024.
//

#include "Engine.h"

#include <iostream>
#include <string>

#include "Shader.h"

const std::string vertexShaderString = R"glsl(
        #version 460 core
        //layout (location = 0) in vec3 position;
        //layout (location = 1) in vec3 color;

        //out vec3 vertex_color;

        void main() {
            gl_Position = vec4(0.5f, 0.5f, 0.0f, 1.0f);
           // gl_Position  = vec4(position, 1.0);
           // vertex_color = color;
        }
    )glsl";

const std::string fragmentShaderString = R"glsl(
        #version 460 core

        //in vec3 vertex_color;
        out vec4 frag_color;

        void main() {
            frag_color = vec4(1.0, 1.0, 0.0, 1.0f);
        }
    )glsl";

Engine::Engine() {
    m_window = new Window(800, 600, "OpenGL Engine");
    m_graphics = new Graphics();
    std::vector<Shader> shaders;
    shaders.emplace_back(GL_VERTEX_SHADER, vertexShaderString.c_str());
    shaders.emplace_back(GL_FRAGMENT_SHADER, fragmentShaderString.c_str());
    m_shaderProgram = new ShaderProgram(shaders);
}

void Engine::run() const {
    //m_shaderProgram->bind();
    while (!m_window->isClosed()) {
        m_window->processInput();
        Graphics::cleanColor();
        //m_shaderProgram->bind();
    }
}
