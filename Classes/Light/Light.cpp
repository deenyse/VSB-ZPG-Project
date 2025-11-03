#include "Light.h"


Light::Light(LightType t, const glm::vec3 c) : type(t), color(c) {};

LightType Light::getType() {
	return type;
}

Light::~Light() = default;