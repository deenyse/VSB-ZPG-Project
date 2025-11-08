#pragma once

#include <vector>
#include "../Object/DrawableObject.h"

#include "../Camera/Camera.h"

#include "../Light/HeadLight.h"
#include "../Light/LightManager.h"

class Scene
{
protected:
	DrawableObject* addObject(DrawableObject* object);
	LightManager* lightManager = new LightManager();
private:
	std::vector<DrawableObject*> objects;
	Camera* camera = new Camera(glm::vec3(0.f, 0.f, 5.f), glm::vec3(0.f, 1.f, 0.f));
	HeadLight* headLight = new HeadLight(camera);

public:
	Scene();
	void renderAll();
	Camera* getCamera() { return camera; }
	void switchHeadLight();
	// LightManager* getLightsManager() { return lightManager; }
};

