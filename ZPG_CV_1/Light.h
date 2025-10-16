#pragma once

#include "Subject.h"

//Include GLEW
#include <GL/glew.h>
#include <glm/vec3.hpp> // glm::vec3

class Light : public Subject
{
private:
	glm::vec3 position;


public:
	Light(glm::vec3 pos);
	void setPosition(glm::vec3 pos);
	glm::vec3 getPosition();
};


