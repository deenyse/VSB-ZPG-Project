#include "Transform.h"

Transform* Transform::addTransform(TransformBase* transform) {
	transforms.push_back(transform);

	return this;
}

void Transform::clearTransformations() {
	transforms.clear();
}


glm::mat4 Transform::getMatrix() {
	glm::mat4 outMatrix = transformMatrix;
	for (const auto& t : transforms) {
		outMatrix = outMatrix * t->getMatrix();
	}

	return outMatrix;
}
