#ifndef SCENE_H
#define SCENE_H
#include "Camera.h"
#include "glm/vec3.hpp"

class ShaderProgram;
class SimpleMesh;

class Scene {
    ShaderProgram * m_defaultProgram;
    SimpleMesh * m_mesh;
    float speed = 0.01f;
    Camera * m_camera;
public:
    explicit Scene(Camera *camera);
    ~Scene();
    void render() const;

    void onKey(int key, int action) const;
};



#endif //SCENE_H
