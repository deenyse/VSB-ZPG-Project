#pragma once

#include <vector>
#include "IBasicTransform.h"
class Transform
{
private:
	std::vector<IBasicTransform*> transforms;
	glm::mat4 transformMatrix = glm::mat4(1.0f);
public:
	void addTransform(IBasicTransform* transform);

	glm::mat4 getTransformMatrix();
};

