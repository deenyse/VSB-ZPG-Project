#pragma once

#include <glm/mat4x4.hpp> // glm::mat4


class IBasicTransform {
public:
	// Return the transformation matrix
    virtual glm::mat4 getMatrix() = 0;
};
