//
// Created by dkadyrov on 16.08.2024.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "glm/fwd.hpp"
#include "glm/vec3.hpp"
#include "glm/matrix.hpp"


class Camera {
    float cameraSpeed = 0.05f; // adjust accordingly
    glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
    glm::mat4x4 m_perspective;
    float lastFrame = 0.0f; // Time of last frame
    void calcCameraSpeed();
public:
    Camera(float width, float height);
    [[nodiscard]] glm::mat4x4 getViewMatrix() const;
    glm::mat4x4 getProjectionMatrix() const;

    void onKey(int key, int action);
    void onResize(float width, float height);
};



#endif //CAMERA_H
