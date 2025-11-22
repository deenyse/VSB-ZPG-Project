#pragma once

#include <list>
#include <vector>
#include "../Object/DrawableObject.h"
#include "../Object/Skydome.h"
#include "../Camera/Camera.h"

#include "../Light/HeadLight.h"
#include "../Light/LightManager.h"
#include "../Model/StructModelSources.h"
#include "../Material/StructMaterials.h"
class Scene
{
protected:
	DrawableObject* addObject(DrawableObject* object);
	LightManager* lightManager = new LightManager();
	Camera* camera = new Camera(glm::vec3(0.f, 1.f, 5.f));
	Skydome* skydome = nullptr;
	std::unordered_map<ShaderType, std::vector<DrawableObject*>> objects;
private:
	HeadLight* headLight = new HeadLight(camera);
	DrawableObject* selectedObject = nullptr;
public:
	Scene();
	void renderAll(float dt);
	Camera* getCamera();
	void bindCameraAndLightToUsedShaders();

	void switchHeadLight();

	virtual void onObjectSelect(GLuint id); // default sets selected object
	DrawableObject* getSelectedObject();

	void onPositionAction(glm::vec3 position);// default spawn object
};

