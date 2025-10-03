#include "Scale.h"

Scale::Scale(int scaleFactor) {
	this->transformationMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(scaleFactor));
}