//
// Created by dkadyrov on 10.08.2024.
//

#ifndef ENGINE_H
#define ENGINE_H
#include "Graphics.h"
#include "ShaderProgram.h"
#include "Window.h"


class Engine {
    Window * m_window;
    Graphics * m_graphics;
    ShaderProgram * m_shaderProgram;
public:
    Engine();
    ~Engine() = default;
    void run() const;
};



#endif //ENGINE_H
