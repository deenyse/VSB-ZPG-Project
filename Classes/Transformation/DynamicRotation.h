#pragma once
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include "Rotate.h"
#include "DynamicTransform.h"

class DynamicRotation : public Rotate, public DynamicTransform
{
private:
    float speed;
public:
    DynamicRotation(float speed, glm::vec3 axis)
        : Rotate (0, glm::normalize(axis)), speed(speed) {
    }

    glm::mat4 getMatrix() override;

    void update(float deltaTime) override;
};

