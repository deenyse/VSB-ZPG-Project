#include "DynamicRotation.h"

glm::mat4 DynamicRotation::getMatrix()
{
    return glm::rotate(glm::mat4(1.0f), angle, axis);
}
void DynamicRotation::update(float deltaTime) {
    angle += speed * deltaTime;
}