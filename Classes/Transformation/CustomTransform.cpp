#include "CustomTransform.h"

CustomTransform::CustomTransform(glm::mat4 m) : matrix(m) {

}

glm::mat4 CustomTransform::getMatrix() {
    return matrix;
}