#pragma once

#include <vector>
#include "DrawableObject.h"

#include "Camera.h"
#include "Light.h"

#include "StructShaderSources.h"
class Scene
{
protected:
	Light* light = new Light(glm::vec3(0.f));
	void virtual initLights() =0;
	void virtual initObjects() =0;
	DrawableObject* addObject(const float* points, int verticiesNum, ShaderPair shaderSource, Light* light);
private:
	std::vector<DrawableObject*> objects;
	Camera* camera = new Camera(glm::vec3(0.f, 0.f, 5.f), glm::vec3(0.f, 1.f, 0.f));

public:
	void renderAll();
	Camera* getCamera() { return camera; }
};

