#pragma once

#include <vector>

#include "TransformBase.h"

class Transform : public TransformBase
{
private:
	std::vector<TransformBase*> transforms;
	glm::mat4 transformMatrix = glm::mat4(1.0f);
public:
	Transform* addTransform(TransformBase* transform);

	glm::mat4 getMatrix() override;
};

