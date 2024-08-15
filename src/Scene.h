#ifndef SCENE_H
#define SCENE_H

class ShaderProgram;
class SimpleMesh;

class Scene {
    ShaderProgram * m_defaultShaderProgram;
    SimpleMesh * m_triangleMesh;
public:
    Scene();
    ~Scene();
    void render() const;
};



#endif //SCENE_H
