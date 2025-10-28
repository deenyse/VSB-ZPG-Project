#pragma once

#include <vector>
#include "DrawableObject.h"

#include "Camera.h"
#include "Light.h"
#define MAX_LIGHTS 4
#include "StructShaderSources.h"
class Scene
{
protected:
	void virtual initLights() =0;
	void virtual initObjects() =0;
	DrawableObject* addObject(DrawableObject* object);
	Light* addLight(Light* light);
private:	
	std::vector<DrawableObject*> objects;
	std::vector<Light*> lights;

	Camera* camera = new Camera(glm::vec3(0.f, 0.f, 5.f), glm::vec3(0.f, 1.f, 0.f));

public:
	void renderAll();
	Camera* getCamera() { return camera; }
	//Light* getLight(int index) { return index >= 0 && index < lights.size() ? lights[index] : nullptr; }
	std::vector<Light*> getLights() { return lights; }
};

