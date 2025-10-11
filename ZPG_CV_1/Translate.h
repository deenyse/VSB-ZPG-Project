#pragma once
//Include GLEW
#include <GL/glew.h>

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective


#include "TransformBase.h"

class Translate : public TransformBase {
private:
    glm::vec3 offset;
public:
    Translate(const glm::vec3& o) : offset(o) {}
    glm::mat4 getMatrix() override;
};
