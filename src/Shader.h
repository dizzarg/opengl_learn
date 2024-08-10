#ifndef SHADER_H
#define SHADER_H
#include <iostream>

class Shader {
private:
    unsigned int m_id;
public:
    Shader(unsigned int type, const char *source);

    Shader(const Shader &other) = default;

    Shader(Shader &&other) noexcept
        : m_id(other.m_id) {
        other.m_id = 0;
    }

    Shader & operator=(const Shader &other) {
        if (this == &other)
            return *this;
        m_id = other.m_id;
        return *this;
    }

    Shader & operator=(Shader &&other) noexcept {
        if (this == &other)
            return *this;
        m_id = other.m_id;
        other.m_id = 0;
        return *this;
    }

    [[nodiscard]] unsigned int getId() const;
    ~Shader();
};

#endif //SHADER_H
