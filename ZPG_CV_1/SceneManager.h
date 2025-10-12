#pragma once
#include <vector>

#include "Scene.h"

#include "Scene_1.h"
#include "Scene_2.h"
#include "Scene_3.h"

class SceneManager
{
private:
	std::vector<Scene*> scenes;
	Scene* currentScene = NULL;
	void addScene(Scene* scene) { scenes.push_back(scene); }

public:
	SceneManager() {
		addScene(new Scene_1());
		//addScene(new Scene_2());
		//addScene(new Scene_3());
		if (!scenes.empty()) currentScene = scenes[0];
	}
	void setScene(int i);
	void renderCurrentScene();
	void handleMouseMovement(float deltaX, float deltaY);
	void handleBtnPress(int key);
	void handleScreenResize(int width, int height);
};



