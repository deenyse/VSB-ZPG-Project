#pragma once

#include <vector>
#include "DrawableObject.h"

#include "Camera.h"
#include "Light.h"

#include "StructShaderSources.h"
class Scene
{
protected:
	Camera* camera = new Camera(glm::vec3(0.f, 0.f, 5.f), glm::vec3(0.f, 1.f, 0.f)); 
	Light* light = new Light(glm::vec3(0.f));
private:
	std::vector<DrawableObject*> objects;
public:
	DrawableObject* addObject(const float* points, int verticiesNum, ShaderPair shaderSource, Light* light);
	void renderAll();
	Camera* getCamera() { return camera; }
};

