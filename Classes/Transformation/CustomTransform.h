#pragma once
#include "TransformBase.h"


class CustomTransform : public TransformBase{
private:
    glm::mat4 matrix;
public:
    CustomTransform(glm::mat4 m);
    glm::mat4 getMatrix() override;
};
