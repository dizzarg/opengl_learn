#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H
#include "ShaderProgram.h"
#include "glm/fwd.hpp"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

struct Vertex {
    float x, y, z;
    float r, g, b;
    // glm::vec3 position;
    // glm::vec3 color;
    //glm::vec2 texture;

};


class SimpleMesh {
    unsigned int vao{0}, vbo{0};
    glm::vec3 m_position = glm::vec3(0.0f);
    glm::vec3 m_scale = glm::vec3(1.0f);
public:
    explicit SimpleMesh(const std::vector<Vertex> &vertices);
    SimpleMesh(const SimpleMesh &) = delete;
    SimpleMesh(SimpleMesh &&) = delete;
    SimpleMesh &operator=(const SimpleMesh &) = delete;
    SimpleMesh &operator=(SimpleMesh &&) = delete;
    ~SimpleMesh();
    void draw(const ShaderProgram &shader) const;

    void scale(glm::vec3 vec);
    void move(glm::vec3 vec);
};



#endif //TRIANGLEMESH_H
