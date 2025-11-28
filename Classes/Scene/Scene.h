#pragma once

#include <list>
#include <vector>
#include "../Object/DrawableObject.h"
#include "../Object/Skydome.h"
#include "../Camera/Camera.h"

#include "../Light/HeadLight.h"
#include "../Light/LightManager.h"
#include "../Model/Models.h"
#include "../Material/StructMaterials.h"
class Scene
{
protected:
	std::unordered_map<ShaderType, std::vector<DrawableObject*>> objects;

	DrawableObject* addObject(DrawableObject* object);
	Light* addLight(Light* light);
	Camera* camera = new Camera(glm::vec3(0.f, 1.f, 5.f));
	Skydome* skydome = nullptr;
private:
	LightManager* lightManager = new LightManager();
	HeadLight* headLight = new HeadLight(camera);
	DrawableObject* selectedObject = nullptr;
public:
	Scene();
	void renderAll(float dt);
	Camera* getCamera();
	void bindCameraAndLightToUsedShaders();

	void switchHeadLight();

	DrawableObject* getSelectedObject();
	virtual void onObjectSelect(GLuint id); // default sets selected object
	virtual void onPositionUpdateAction(glm::vec3 position);
};

