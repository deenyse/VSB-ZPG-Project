#pragma once

#include <vector>
#include "DrawableObject.h"

#include "Camera.h"
#include "Light.h"
#define MAX_LIGHTS 4
#include "StructShaderSources.h"

#include "HeadLight.h"
class Scene
{
protected:
	void virtual initLights() =0;
	void virtual initObjects() =0;
	void initScene();
	DrawableObject* addObject(DrawableObject* object);
	Light* addLight(Light* light);
private:	
	std::vector<DrawableObject*> objects;
	std::vector<Light*> lights;
	Camera* camera = new Camera(glm::vec3(0.f, 0.f, 5.f), glm::vec3(0.f, 1.f, 0.f));
	HeadLight* headLight = new HeadLight(camera);
public:
	Scene();
	void renderAll();
	Camera* getCamera() { return camera; }
	void switchHeadLight();
	std::vector<Light*> getLights() { return lights; }
};

