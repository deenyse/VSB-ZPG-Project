#pragma once
#include <vector>

#include "Scene.h"


class SceneManager
{
private:
	std::vector<Scene*> scenes;
	Scene* currentScene = nullptr;
	void addScene(Scene* scene);


public:
	SceneManager();

	void renderCurrentScene();
	Scene* getCurrentScene();

	void updateCameraPosition(int direction, glm::vec2 mouseOffset, float deltaTime);
	void switchHeadLight();
	void setScene(int id);
	void handleScreenResize(int width, int height);
};



