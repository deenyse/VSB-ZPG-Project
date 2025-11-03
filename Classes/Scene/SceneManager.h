#pragma once
#include <vector>

#include "Scene.h"
#include "../Application/EnumMooveDirections.h"
#include "Scene_1.h"
#include "Scene_2.h"
#include "Scene_3.h"

class SceneManager
{
private:
	std::vector<Scene*> scenes;
	Scene* currentScene = NULL;
	void addScene(Scene* scene);

public:
	SceneManager();
	void renderCurrentScene();
	void handleMouseMovement(float deltaX, float deltaY);
	void moveCamera(int direction);
	void switchHeadLight();
	void setScene(int id);
	void handleScreenResize(int width, int height);
};



