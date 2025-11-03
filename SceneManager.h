#pragma once
#include <vector>

#include "Scene.h"

#include "Scene_1.h"
#include "Scene_2.h"
#include "Scene_3.h"

//Make singleton???
class SceneManager
{
private:
	std::vector<Scene*> scenes;
	Scene* currentScene = NULL;
	void addScene(Scene* scene);
	void setScene(int i);

public:
	SceneManager();
	void renderCurrentScene();
	void handleMouseMovement(float deltaX, float deltaY);
	void handleBtnPress(int key);
	void handleScreenResize(int width, int height);
};



