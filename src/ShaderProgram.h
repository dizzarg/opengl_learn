#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include <vector>

class Shader;

class ShaderProgram {
    unsigned int m_id;
public:
    explicit ShaderProgram(const std::vector<Shader>& shaders);

    ShaderProgram(const ShaderProgram &other) = default;

    ShaderProgram(ShaderProgram &&other) noexcept
        : m_id(other.m_id) {
        other.m_id = 0;
    }

    ShaderProgram & operator=(const ShaderProgram &other) {
        if (this == &other)
            return *this;
        m_id = other.m_id;
        return *this;
    }

    ShaderProgram & operator=(ShaderProgram &&other) noexcept {
        if (this == &other)
            return *this;
        m_id = other.m_id;
        other.m_id = 0;
        return *this;
    }

    ~ShaderProgram();
    void bind() const;
    static void unbind();
    [[nodiscard]] unsigned int getId() const;
};



#endif //SHADERPROGRAM_H
