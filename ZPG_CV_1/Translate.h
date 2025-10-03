#pragma once
//Include GLEW
#include <GL/glew.h>

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective


#include "IBasicTransform.h"

class Translate : public IBasicTransform {
private:
    glm::vec3 offset;
public:
    Translate(const glm::vec3& o) : offset(o) {}
    glm::mat4 getMatrix() override;
};
