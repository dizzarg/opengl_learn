#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H
#include "ShaderProgram.h"
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
    unsigned int vao{}, vbo{};
public:
    explicit SimpleMesh(const ShaderProgram &shader, const std::vector<Vertex> &vertices);
    SimpleMesh(const SimpleMesh &) = delete;
    SimpleMesh(SimpleMesh &&) = delete;
    SimpleMesh &operator=(const SimpleMesh &) = delete;
    SimpleMesh &operator=(SimpleMesh &&) = delete;
    ~SimpleMesh();
    void draw() const;
};



#endif //TRIANGLEMESH_H
