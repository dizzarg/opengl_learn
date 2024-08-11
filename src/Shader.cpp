#include "Shader.h"
#include <glad/glad.h>
#include <iostream>

Shader::Shader(const unsigned int type, const char *source) {
    int success;
    const GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        m_id = 0;
    }
    m_id = shader;
}

unsigned int Shader::getId() const {
    return m_id;
}

Shader::~Shader() {
    glDeleteShader(m_id);
}

