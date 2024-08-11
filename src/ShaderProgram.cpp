#include "ShaderProgram.h"
#include <glad/glad.h>
#include <iostream>

#include "Shader.h"

ShaderProgram::ShaderProgram(const std::vector<Shader>& shaders) {
    const GLuint program = glCreateProgram();
    for (const auto& shader : shaders) {
        glAttachShader(program, shader.getId());
    }
    glLinkProgram(program);
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAMM::COMPILATION_FAILED\n" << infoLog << std::endl;
        m_id = 0;
    }
    m_id = program;
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(m_id);
}

void ShaderProgram::bind() const {
    glUseProgram(m_id);
}

void ShaderProgram::unbind() {
    glUseProgram(0);
}

unsigned int ShaderProgram::getId() const {
    return m_id;
}

