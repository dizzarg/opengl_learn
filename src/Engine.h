#ifndef ENGINE_H
#define ENGINE_H

class Window;
class Graphics;
class Scene;

class Engine {
    Window * m_window;
    Graphics * m_graphics;
    Scene * m_scene;

public:
    Engine();
    ~Engine();
    void run() const;
};



#endif //ENGINE_H
