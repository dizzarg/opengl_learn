//
// Created by dkadyrov on 15.08.2024.
//

#include "Scene.h"

#include <vector>
#include <glad/glad.h>

#include "Shader.h"
#include "SimpleMesh.h"
#include "GLFW/glfw3.h"

// language=glsl
auto vertexShaderString = R"glsl(
        #version 460 core
        layout (location = 0) in vec3 position;
        layout (location = 1) in vec3 color;

        out vec3 vertex_color;

        //uniform mat4 projection;
       // uniform mat4 view;
        uniform mat4 model;

        void main() {
           gl_Position  = model * vec4(position, 1.0);
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
        }
    )glsl";

Scene::Scene() {
    std::vector<Shader> shaders;
    shaders.emplace_back(GL_VERTEX_SHADER, vertexShaderString);
    shaders.emplace_back(GL_FRAGMENT_SHADER, fragmentShaderString);
    m_defaultProgram = new ShaderProgram(shaders);
    const std::vector<Vertex> vertices = {
        {-0.5, -0.5, 0, 1.0f, 0.0f, 0.0f},
        {0.5, -0.5, 0,  0.0f, 1.0f, 0.0f},
        {0.5, 0.5, 0,   0.0f, 0.0f, 1.0f},

        {-0.5, 0.5, 0,  0.0f, 1.0f, 0.0f},
        {-0.5, -0.5, 0, 1.0f, 0.0f, 0.0f},
        {0.5, 0.5, 0,   0.0f, 0.0f, 1.0f}
    };
    m_mesh = new SimpleMesh(vertices);
}

Scene::~Scene() {
    delete m_defaultProgram;
    delete m_mesh;
}

void Scene::render() const {
    m_mesh->draw(*m_defaultProgram);
}

void Scene::onKey(const int key, const int action) const {
    if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
        m_mesh->scale(glm::vec3(0, 0.1f, 0));
    }
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
        m_mesh->scale(glm::vec3(0, -0.1f, 0));
    }
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
        m_mesh->scale(glm::vec3(0.1f, 0, 0));
    }
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
        m_mesh->scale(glm::vec3(-0.1f, 0, 0));
    }
}
