#pragma once

#include <vector>

#include "IBasicTransform.h"

#include <glm/mat4x4.hpp> // glm::mat4

class Transform
{
private:
	std::vector<IBasicTransform*> transformations;
	glm::mat4 worldMatrix;

	void updateMatrix() { worldMatrix = glm::mat4(1.0f); for (auto* t : transformations) t->updateMatrix(worldMatrix); }
public:
	Transform() : worldMatrix(1.0f) {}
	void addTransformation(IBasicTransform* t) { transformations.push_back(t); };
	
	
	glm::mat4 getWorldMatrix() {
		this->updateMatrix();
		return worldMatrix; 
	}

	~Transform() { for (auto* t : transformations) delete t; }
};

