#ifndef SCENE_H
#define SCENE_H

class ShaderProgram;
class SimpleMesh;

class Scene {
    ShaderProgram * m_defaultProgram;
    SimpleMesh * m_mesh;
    float speed = 0.01f;
public:
    Scene();
    ~Scene();
    void render() const;

    void onKey(int key, int action) const;
};



#endif //SCENE_H
