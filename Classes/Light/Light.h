#pragma once

#include "../Observer/Subject.h"
#include "EnumLightType.h"	

//Include GLEW
#include <GL/glew.h>
#include <glm/vec3.hpp> // glm::vec3



class Light : public Subject
{
private:
	LightType type;
public:
	glm::vec3 color;
	bool isOn = true;
	Light(LightType t, const glm::vec3 c);
	LightType getType();
	virtual ~Light() = 0;
};