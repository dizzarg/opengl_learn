#ifndef WINDOW_H
#define WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(unsigned int width, unsigned int height, const char * title);

    ~Window();

    [[nodiscard]] bool isClosed() const;

    void processInput() const;

    Window(const Window &other) = delete;

    Window(Window &&other) = delete;

    Window & operator=(const Window &other) = delete;

    Window & operator=(Window &&other) noexcept = delete;

    [[nodiscard]] unsigned int getHeight() const {
        return m_height;
    }
    [[nodiscard]] unsigned int getWidth() const {
        return m_width;
    }

private:
    GLFWwindow * m_window;
    const unsigned int m_height;
    const unsigned int m_width;
};

#endif //WINDOW_H
