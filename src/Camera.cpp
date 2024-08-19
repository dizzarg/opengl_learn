//
// Created by dkadyrov on 16.08.2024.
//

#include "Camera.h"

#include "GLFW/glfw3.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

Camera::Camera(const float width, const float height) : m_perspective(glm::perspective(glm::radians(45.0f), width/ height, 0.1f, 100.0f)) {

}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::calcCameraSpeed() {
    // float currentFrame = glfwGetTime();
    // cameraSpeed =  0.5f * currentFrame - lastFrame;
    // lastFrame = currentFrame;
}

void Camera::onKey(const int key, const int action) {

    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        calcCameraSpeed();
        if (key == GLFW_KEY_W)
            cameraPos += cameraSpeed * cameraFront;
        if (key == GLFW_KEY_S)
            cameraPos -= cameraSpeed * cameraFront;
        if (key == GLFW_KEY_A)
            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        if (key == GLFW_KEY_D)
            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }
}

glm::mat4x4 Camera::getProjectionMatrix() const {
    return m_perspective;
}

void Camera::onResize(float width, float height) {
    m_perspective = glm::ortho(-width / 2, width / 2, -height / 2, height / 2);
    //m_perspective = glm::perspective(glm::radians(45.0f), width/height, 0.1f, 100.0f);
}
