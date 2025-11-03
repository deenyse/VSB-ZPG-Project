#pragma once

#include <glm/mat4x4.hpp> // glm::mat4

class TransformBase {
public:
	virtual glm::mat4 getMatrix() = 0;
};
