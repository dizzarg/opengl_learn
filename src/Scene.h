#ifndef SCENE_H
#define SCENE_H
#include "glm/vec3.hpp"

class ShaderProgram;
class SimpleMesh;

class Scene {
    ShaderProgram * m_defaultProgram;
    SimpleMesh * m_mesh;
    float speed = 0.01f;
    glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
public:
    Scene();
    ~Scene();
    void render() const;

    void onKey(int key, int action);
};



#endif //SCENE_H
