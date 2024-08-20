#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H
#include "glm/fwd.hpp"
#include "glm/vec2.hpp"
#include "glm/detail/type_quat.hpp"


struct Vertex;
class ShaderProgram;

class SimpleMesh {
    unsigned int vao{0}, vbo{0};
    glm::vec3 m_position = glm::vec3(0.0f);
    glm::vec3 m_scale = glm::vec3(1.0f);
    float m_rotationX_Angle = 30.0f;
    float m_rotationY_Angle = -45.0f;
    float m_rotationZ_Angle = 0.0f;
    unsigned int m_vertice_count;
    unsigned int m_stride;

public:
    SimpleMesh(const std::vector<Vertex> &vertices, int stride);
    SimpleMesh(const SimpleMesh &) = delete;
    SimpleMesh(SimpleMesh &&) = delete;
    SimpleMesh &operator=(const SimpleMesh &) = delete;
    SimpleMesh &operator=(SimpleMesh &&) = delete;
    ~SimpleMesh();
    void draw(const ShaderProgram &shader) const;

    void scale(glm::vec3 vec);
    void move(glm::vec3 vec);

    void rotateZ(float angle);
    void rotateX(float angle);
    void rotateY(float angle);
};



#endif //TRIANGLEMESH_H
