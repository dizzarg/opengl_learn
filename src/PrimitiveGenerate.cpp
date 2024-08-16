//
// Created by dkadyrov on 16.08.2024.
//

#include "PrimitiveGenerate.h"

#include <vector>
#include "Vertex.h"


std::vector<Vertex> PrimitiveGenerate::generateCube() {
    const std::vector<Vertex> cube = {
        {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},
        {glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},
        {glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},
        {glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},
        {glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},

        {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},
        {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},
        {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},
        {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},
        {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},
        {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.1f, 0.4f)},

        {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},
        {glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},
        {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},
        {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},

        {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.3f, 0.0f, 0.0f)},

        {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.6f, 0.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.6f, 0.0f)},
        {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.6f, 0.0f)},
        {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.6f, 0.0f)},
        {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.6f, 0.0f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.6f, 0.0f)},

        {glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.6f, 0.0f)},
        {glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.6f, 0.0f)},
        {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.6f, 0.0f)},
        {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.6f, 0.0f)},
        {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.6f, 0.0f)},
        {glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.6f, 0.0f)}
    };
    return cube;
}
