#include "Transform.h"

#include "DynamicTransform.h"

Transform* Transform::addTransform(TransformBase* transform) {
	transforms.push_back(transform);
	notify(STransformations);
	return this;
}

void Transform::clearTransformations() {
	transforms.clear();
}

void Transform::updateDynamicTransforms(float deltaTime) {
	for (auto t : transforms) {
		if (auto dt = dynamic_cast<DynamicTransform*>(t)) {
			dt->update(deltaTime);
		}
	}
	notify(STransformations);
}

glm::mat4 Transform::getMatrix() {
	glm::mat4 outMatrix = transformMatrix;
	for (const auto& t : transforms) {
		outMatrix = outMatrix * t->getMatrix();
	}

	return outMatrix;
}
