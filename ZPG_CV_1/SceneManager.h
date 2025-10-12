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
	void setScene(int i) { if (i >= 0 && i < scenes.size()) currentScene = scenes[i]; }
	void renderCurrentScene() { if (currentScene) currentScene->renderAll(); }
	void handleMouseMovement(float deltaX, float deltaY) { if (currentScene) currentScene->getCamera()->updateOrientation(deltaX, deltaY); }
};


//void App::createScenes() {
//	scenes.push_back(new Scene_1());
//	//scenes.push_back(new Scene_2());
//	//scenes.push_back(new Scene_3());
//
//	currentScene = scenes[0];
//	inputManager->setScene(currentScene);
//}
//void App::setScene(int i) {
//	if (i < 1 || i > scenes.size()) return;
//	currentScene = scenes[i - 1];
//	printf("Switched to scene %d \n", i);
//}


