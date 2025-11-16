#pragma once
#include "TransformBase.h"

class MergedTransform : public TransformBase{
private:
    glm::mat4 mergedTransforms;
public:
    MergedTransform(glm::mat4 mergedMatrix);
    glm::mat4 getMatrix() override;
};