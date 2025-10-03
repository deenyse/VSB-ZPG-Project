#pragma once

//Include GLEW
#include <GL/glew.h>

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective


#include "IBasicTransform.h"

class Scale : public IBasicTransform
{
private:
    glm::vec3 factor;
public:
    Scale(const glm::vec3& f) : factor(f) {}
    glm::mat4 getMatrix() override;
};

