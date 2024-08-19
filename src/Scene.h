#ifndef SCENE_H
#define SCENE_H

class ShaderProgram;
class SimpleMesh;
class Camera;

class Scene {
    ShaderProgram * m_defaultProgram;
    SimpleMesh * m_mesh;
    Camera * m_camera;
    float speed = 0.01f;

public:
    explicit Scene(Camera *camera);
    ~Scene();
    void render() const;

    void onKey(int key, int action) const;
};



#endif //SCENE_H
