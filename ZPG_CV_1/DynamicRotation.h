#pragma once
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include "TransformBase.h"

class DynamicRotation : public TransformBase
{
private:
    float speed;
    glm::vec3 axis;
    float angle = 0.0f; 
public:
    DynamicRotation(float speed, glm::vec3 axis)
        : speed(speed), axis(glm::normalize(axis)) {
    }

    glm::mat4 getMatrix()
    {
        angle += speed; 
        return glm::rotate(glm::mat4(1.0f), angle, axis);
    }
};

