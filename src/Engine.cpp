#include "Engine.h"

#include <iostream>
#include <string>
#include "Graphics.h"
#include "Scene.h"
#include "Window.h"
#include "SimpleMesh.h"
#include "Camera.h"

Engine::Engine()
{
    m_window = new Window(800, 600, "OpenGL Engine");
    m_graphics = new Graphics();
    const auto camera = new Camera(static_cast<float>(800), static_cast<float>(600));
    m_scene = new Scene(camera);
    m_window->setScene(m_scene);
    m_window->setCamera(camera);
}

Engine::~Engine()
{
    delete m_scene;
    delete m_graphics;
    delete m_window;
}

void Engine::run() const
{
    m_graphics->enableDepth();
    while (!m_window->shouldClose())
    {
        m_window->processInput();
        m_graphics->cleanBits();
        Graphics::cleanColor(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));
        m_scene->render();
    }
}
