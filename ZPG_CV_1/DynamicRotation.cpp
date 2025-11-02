#include "DynamicRotation.h"

glm::mat4 DynamicRotation::getMatrix()
{
    angle += speed;
    return glm::rotate(glm::mat4(1.0f), angle, axis);
}