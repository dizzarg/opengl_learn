#include "Engine.h"

#include <iostream>
#include <string>
#include "Graphics.h"
#include "Scene.h"
#include "Window.h"
#include "SimpleMesh.h"

Engine::Engine() {
    m_window = new Window(800, 600, "OpenGL Engine");
    m_graphics = new Graphics();
    m_scene = new Scene();
    m_window->setScene(m_scene);
}

Engine::~Engine() {
    delete m_scene;
    delete m_graphics;
    delete m_window;
}

void Engine::run() const {
    while (!m_window->shouldClose()) {
        m_window->processInput();
        Graphics::cleanColor();
        m_scene->render();
    }
}
