#ifndef WINDOW_H
#define WINDOW_H

class Camera;
struct GLFWwindow;
class Scene;

class Window {
public:
    Window(unsigned int width, unsigned int height, const char * title);

    ~Window();

    [[nodiscard]] bool shouldClose() const;

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

    void setScene(Scene *scene) {
        m_scene = scene;
    }

    void setCamera(Camera * camera) {
        m_camera = camera;
    }

private:
    GLFWwindow * m_window;
    const unsigned int m_height;
    const unsigned int m_width;
    Scene * m_scene = nullptr;
    Camera * m_camera = nullptr;
};

#endif //WINDOW_H
