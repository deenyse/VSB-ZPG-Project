#pragma once

#include <vector>
#include "../Object/DrawableObject.h"
#include "../Object/Skydome.h"
#include "../Camera/Camera.h"

#include "../Light/HeadLight.h"
#include "../Light/LightManager.h"
#include "../Shader/StructShaderSources.h"
#include "../Model/StructModelSources.h"

class Scene
{
protected:
	DrawableObject* addObject(DrawableObject* object);
	LightManager* lightManager = new LightManager();
	Skydome* skydome = nullptr;
private:
	std::vector<DrawableObject*> objects;
	Camera* camera = new Camera(glm::vec3(0.f, 0.f, 5.f), glm::vec3(0.f, 1.f, 0.f));
	HeadLight* headLight = new HeadLight(camera);
	DrawableObject* selectedObject = nullptr;
public:
	Scene();
	void renderAll();
	Camera* getCamera() { return camera; }
	void switchHeadLight();
	void setSelectedObject(GLuint id);
	DrawableObject* getSelectedObject() { return selectedObject; }
	void spawnObject(glm::vec3 position);
};

