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
	void handleMouseMovement(float deltaX, float deltaY);
	void moveCamera(int direction);
	void switchHeadLight();
	void setScene(int id);
	void handleScreenResize(int width, int height);
};



