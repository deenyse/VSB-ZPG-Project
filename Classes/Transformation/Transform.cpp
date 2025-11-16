#include "Transform.h"

#include "MergedTransform.h"

Transform* Transform::addTransform(TransformBase* transform) {
	transforms.push_back(transform);
	if (transforms.size() > 10) {
		auto MT = new MergedTransform(this->getMatrix());
		transforms.clear();
		transforms.push_back(MT);
	}

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
