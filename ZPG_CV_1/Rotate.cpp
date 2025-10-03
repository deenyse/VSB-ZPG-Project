#include "Rotate.h"

Rotate::Rotate(float angle, glm::vec3 axis)
{
	transformationMatrix = glm::rotate(glm::mat4(1.0f), angle, axis);
}

//glm::rotate(M, angle, glm::vec3(1.0f, 0.0f, 0.0f));