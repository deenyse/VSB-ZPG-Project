#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>  


#include <glm/vec3.hpp> // glm::vec3
#include <glm/mat4x4.hpp> // glm::mat4


class IBasicTransform {
protected:
	glm::mat4 transformationMatrix;  //basic vector for transformations

public:
	virtual ~IBasicTransform() = default;
	virtual void updateMatrix(glm::mat4& matrix) = 0;  // Matrix transformation method
};