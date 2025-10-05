#include "Transform.h"

void Transform::addTransform(IBasicTransform* transform) {
	transforms.push_back(transform);
}


glm::mat4 Transform::getTransformMatrix() {
	glm::mat4 outMatrix = transformMatrix;
	for (const auto& t : transforms) {
		outMatrix = t->getMatrix() * outMatrix;
	}

	return outMatrix;
}
