#include "SimpleMesh.h"
#include <glad/glad.h>
#include "ShaderProgram.h"

SimpleMesh::SimpleMesh(const ShaderProgram &shader, const std::vector<Vertex> &vertices)  {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,vertices.size() * sizeof(Vertex),  &vertices.front(),GL_STATIC_DRAW);
    // position attribute
    const GLint posAttrib = glGetAttribLocation(shader.getId(), "position");
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(posAttrib);
    // color attribute
    const GLint colorAttrib = glGetAttribLocation(shader.getId(), "color");
    glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), reinterpret_cast<GLvoid *>(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(colorAttrib);

    glBindVertexArray(0);
}

SimpleMesh::~SimpleMesh() {
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

void SimpleMesh::draw() const {
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
