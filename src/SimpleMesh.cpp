#include "SimpleMesh.h"
#include <glad/glad.h>
#include "ShaderProgram.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

SimpleMesh::SimpleMesh( const std::vector<Vertex> &vertices)  {
    glGenVertexArrays(1, &vao);
    // begin VAO
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,vertices.size() * sizeof(Vertex),  &vertices.front(),GL_STATIC_DRAW);

    // end VAO
    glBindVertexArray(0);
}

SimpleMesh::~SimpleMesh() {
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

void SimpleMesh::draw(const ShaderProgram &shader) const {
    shader.bind();

    auto model = glm::mat4(1.0f);
    model = glm::translate(model, m_position);
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

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
    ShaderProgram::unbind();
}

void SimpleMesh::scale(const glm::vec3 vec) {
    m_scale+=vec;
}

void SimpleMesh::move(const glm::vec3 vec) {
    m_position+=vec;
}
