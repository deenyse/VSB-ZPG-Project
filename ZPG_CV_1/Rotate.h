#pragma once

//Include GLEW
#include <GL/glew.h>

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective


#include "IBasicTransform.h"

class Rotate : public IBasicTransform {
private:
    float angle;
    glm::vec3 axis;
public:
    Rotate(float a, const glm::vec3& ax) : angle(a), axis(ax) {}
    glm::mat4 getMatrix() override;
};

