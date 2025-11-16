#pragma once

#include <vector>

#include "TransformBase.h"
#include "../Observer/Subject.h"
#include "../Observer/EnumObservableSubjects.h"

class Transform : public TransformBase , public Subject
{
private:
	bool isDirty = false;
	std::vector<TransformBase*> transforms;
	glm::mat4 transformMatrix = glm::mat4(1.0f);
public:
	Transform* addTransform(TransformBase* transform);
	void clearTransformations();
	void updateDynamicTransforms(float deltaTime);
	glm::mat4 getMatrix() override;

};

