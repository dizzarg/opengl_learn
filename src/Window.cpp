#include "Window.h"

#include "includes.h"
#include "Scene.h"
#include "Camera.h"

Window::Window(const unsigned int width, const unsigned int height, const char *title): m_height(height), m_width(width) {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!m_window) {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLFW window");
    }

    glfwMakeContextCurrent(m_window);

    glfwSetWindowUserPointer(m_window, this);
    glfwSetKeyCallback(m_window, [](GLFWwindow *window, int key, int scancode, int action, int mode) {
        const auto *pw = static_cast<Window *>(glfwGetWindowUserPointer(window));
        if (pw->m_scene != nullptr) {
            pw->m_scene->onKey(key, action);
        }
        if (pw->m_camera != nullptr) {
            pw->m_camera->onKey(key, action);
        }
    });
    glfwSetWindowUserPointer(m_window, this);
    glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow *window, int w, int h) {
        glViewport(0, 0, w, h);
        const auto *pw = static_cast<Window *>(glfwGetWindowUserPointer(window));
        if (pw->m_camera != nullptr) {
            pw->m_camera->onResize(w, h);
        }
    });
}

Window::~Window() {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(m_window);
}

void Window::processInput() const {
    glfwSwapBuffers(m_window);
    glfwPollEvents();

    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_window, true);
    }
    if (glfwGetKey(m_window, GLFW_KEY_L) == GLFW_PRESS) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    if (glfwGetKey(m_window, GLFW_KEY_F) == GLFW_PRESS) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}
