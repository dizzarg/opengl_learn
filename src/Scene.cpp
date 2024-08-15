//
// Created by dkadyrov on 15.08.2024.
//

#include "Scene.h"

#include <vector>
#include <glad/glad.h>

#include "Shader.h"
#include "SimpleMesh.h"

// language=glsl
auto vertexShaderString = R"glsl(
        #version 460 core
        layout (location = 0) in vec3 position;
        layout (location = 1) in vec3 color;

        out vec3 vertex_color;

        void main() {
           gl_Position  = vec4(position, 1.0);
           vertex_color = color;
        }
    )glsl";

// language=glsl
auto fragmentShaderString = R"glsl(
        #version 460 core

        in vec3 vertex_color;
        out vec4 frag_color;

        void main() {
            frag_color = vec4(vertex_color, 1.0f);
            //frag_color = vec4(0.3f, 0.5f, 0.5f, 1.0f);
        }
    )glsl";

Scene::Scene() {
    std::vector<Shader> shaders;
    shaders.emplace_back(GL_VERTEX_SHADER, vertexShaderString);
    shaders.emplace_back(GL_FRAGMENT_SHADER, fragmentShaderString);
    m_defaultShaderProgram = new ShaderProgram(shaders);
    const std::vector<Vertex> vertices = {
        {-0.5, -0.5, 0, 1.0f, 0.0f, 0.0f},
        {0.5, -0.5, 0,  0.0f, 1.0f, 0.0f},
        {0.5, 0.5, 0,   0.0f, 0.0f, 1.0f},

        {-0.5, 0.5, 0,  0.0f, 1.0f, 0.0f},
        {-0.5, -0.5, 0, 1.0f, 0.0f, 0.0f},
        {0.5, 0.5, 0,   0.0f, 0.0f, 1.0f}
    };
    m_triangleMesh = new SimpleMesh(vertices);
}

Scene::~Scene() {
    delete m_defaultShaderProgram;
    delete m_triangleMesh;
}

void Scene::render() const {
    m_triangleMesh->draw(*m_defaultShaderProgram);
}
