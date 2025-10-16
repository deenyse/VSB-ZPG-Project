#include "Light.h"


Light::Light(glm::vec3 pos) : position(pos) {}

void Light::setPosition(glm::vec3 pos) {
	position = pos;
	notify(SubjectsEnum::SLight);
}


glm::vec3 Light::getPosition() 
{ 
	return position; 
}
