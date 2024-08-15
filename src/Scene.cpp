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
        {glm::vec3(-0.5, -0.5, 0), glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(0.5, -0.5, 0), glm::vec3(0.0f, 1.0f, 0.0f)},
        {glm::vec3(0.5, 0.5, 0), glm::vec3(0.0f, 0.0f, 1.0f)},

        {glm::vec3(-0.5, 0.5, 0), glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5, -0.5, 0), glm::vec3(1.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5, 0.5, 0), glm::vec3(0.0f, 0.0f, 1.0f)},
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
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_PAGE_UP:
                m_mesh->scale(glm::vec3(0, 0.1f, 0));
                break;
            case GLFW_KEY_PAGE_DOWN:
                m_mesh->scale(glm::vec3(0, -0.1f, 0));
                break;
            case GLFW_KEY_HOME:
                m_mesh->scale(glm::vec3(0.1f, 0, 0));
                break;
            case GLFW_KEY_END:
                m_mesh->scale(glm::vec3(-0.1f, 0, 0));
                break;
            case GLFW_KEY_UP:
                m_mesh->move(glm::vec3(0, 0.1f, 0));
            break;
            case GLFW_KEY_DOWN:
                m_mesh->move(glm::vec3(0, -0.1f, 0));
            break;
            case GLFW_KEY_LEFT:
                m_mesh->move(glm::vec3(-0.1f, 0, 0));
            break;
            case GLFW_KEY_RIGHT:
                m_mesh->move(glm::vec3(0.1f, 0, 0));
            break;
            case GLFW_KEY_E:
                m_mesh->rotateZ(-0.1f);
            break;
            case GLFW_KEY_Q:
                m_mesh->rotateZ(0.1f);
            break;
            default: ;
        }
    }
}
