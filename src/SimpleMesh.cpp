#include "SimpleMesh.h"
#include <glad/glad.h>
#include "ShaderProgram.h"
#include "Vertex.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

SimpleMesh::SimpleMesh( const std::vector<Vertex> &vertices): m_vertice_count(vertices.size()) {
    glGenVertexArrays(1, &vao);
    // begin VAO
    glBindVertexArray(vao);
    auto data = new float[m_vertice_count * 6];
    for(int i = 0; i < m_vertice_count; i++) {
        data[i*6 + 0] = vertices[i].position.x;
        data[i*6 + 1] = vertices[i].position.y;
        data[i*6 + 2] = vertices[i].position.z;
        data[i*6 + 3] = vertices[i].color.r;
        data[i*6 + 4] = vertices[i].color.g;
        data[i*6 + 5] = vertices[i].color.b;
    }
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, m_vertice_count * 6 * sizeof(float),  data,GL_STATIC_DRAW);
    delete[] data;

    // end VAO
    glBindVertexArray(0);
}

SimpleMesh::~SimpleMesh() {
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

void SimpleMesh::draw(const ShaderProgram &shader) const {
    auto model = glm::mat4(1.0f);
    model = glm::translate(model, m_position);
    model = glm::rotate(model, glm::radians(m_rotationX_Angle), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(m_rotationY_Angle), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(m_rotationZ_Angle), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, m_scale);
    glUniformMatrix4fv(glGetUniformLocation(shader.getId(), "model"), 1, GL_FALSE, glm::value_ptr(model));

    glBindVertexArray(vao);
    // position attribute
    const GLint posAttrib = glGetAttribLocation(shader.getId(), "position");
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(posAttrib);
    // color attribute
    const GLint colorAttrib = glGetAttribLocation(shader.getId(), "color");
    glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), reinterpret_cast<GLvoid *>(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(colorAttrib);

    glDrawArrays(GL_TRIANGLES, 0, m_vertice_count);
    glBindVertexArray(0);
    ShaderProgram::unbind();
}

void SimpleMesh::scale(const glm::vec3 vec) {
    m_scale+=vec;
}

void SimpleMesh::move(const glm::vec3 vec) {
    m_position+=vec;
}

void SimpleMesh::rotateZ(const float angle) {
    m_rotationZ_Angle+=angle;
}

void SimpleMesh::rotateX(const float angle) {
    m_rotationZ_Angle+=angle;
}

void SimpleMesh::rotateY(const float angle) {
    m_rotationY_Angle+=angle;
}

