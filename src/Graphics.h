//
// Created by dkadyrov on 10.08.2024.
//

#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H
#include "glm/vec4.hpp"

class Graphics {
    unsigned int clearBits;
public:
    Graphics();
    ~Graphics();

    void enableDepth();

    void cleanBits() const;

    static void cleanColor(glm::vec4 color);
};



#endif //GRAPHICSENGINE_H
