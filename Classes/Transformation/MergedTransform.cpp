#include "MergedTransform.h"


MergedTransform::MergedTransform(glm::mat4 mergedMatrix) : mergedTransforms(mergedMatrix) {};

glm::mat4 MergedTransform::getMatrix() {
    return mergedTransforms;
}