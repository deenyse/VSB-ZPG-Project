#pragma once
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include "Rotate.h"

class DynamicRotation : public Rotate
{
private:
    float speed;
public:
    DynamicRotation(float speed, glm::vec3 axis)
        : Rotate (0, glm::normalize(axis)), speed(speed) {
    }

    glm::mat4 getMatrix() override;
};

