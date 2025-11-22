#pragma once

#include <list>
#include <vector>
#include "../Object/DrawableObject.h"
#include "../Object/Skydome.h"
#include "../Camera/Camera.h"

#include "../Light/HeadLight.h"
#include "../Light/LightManager.h"
#include "../Shader/ShaderSources.h"
#include "../Model/StructModelSources.h"
#include "../Material/StructMaterials.h"
class Scene
{
protected:
	DrawableObject* addObject(DrawableObject* object);
	LightManager* lightManager = new LightManager();
	Skydome* skydome = nullptr;
	Camera* camera = new Camera(glm::vec3(0.f, 1.f, 5.f));
private:
	std::unordered_map<ShaderType, std::vector<DrawableObject*>> objects;
	// std::vector<DrawableObject*> objects;
	HeadLight* headLight = new HeadLight(camera);
	DrawableObject* selectedObject = nullptr;
public:
	Scene();
	void renderAll(float dt);
	Camera* getCamera();
	void bindCameraAndLightToUsedShaders();

	void switchHeadLight();

	void setSelectedObject(GLuint id);
	DrawableObject* getSelectedObject();

	void spawnObject(glm::vec3 position);
};

