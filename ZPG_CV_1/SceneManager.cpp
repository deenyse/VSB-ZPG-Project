#include "SceneManager.h"

SceneManager::SceneManager() {
	addScene(new Scene_1());
	//addScene(new Scene_2());
	//addScene(new Scene_3());


	if (!scenes.empty()) currentScene = scenes[0];
}

void SceneManager::addScene(Scene* scene) 
{ 
	scenes.push_back(scene); 
}

void SceneManager::setScene(int i) 
{
	if (i >= 0 && i < scenes.size()) currentScene = scenes[i]; 
}

void SceneManager::renderCurrentScene() 
{ 
	if (currentScene) currentScene->renderAll(); 
}

void SceneManager::handleMouseMovement(float deltaX, float deltaY) 
{
	if (currentScene) currentScene->getCamera()->updateOrientation(deltaX, deltaY); 
}

void SceneManager::handleBtnPress(int key) 
{
	if(key == GLFW_KEY_W)
		currentScene->getCamera()->forward();
	else if (key == GLFW_KEY_S)
		currentScene->getCamera()->backward();
	else if (key == GLFW_KEY_A)
		currentScene->getCamera()->left();
	else if (key == GLFW_KEY_D)
		currentScene->getCamera()->right();
	else if (key == GLFW_KEY_1)
		setScene(0);
	else if (key == GLFW_KEY_2)
		setScene(1);
	else if (key == GLFW_KEY_3)
		setScene(2);
	else if (key == GLFW_KEY_4)
		setScene(3);
}

void SceneManager::handleScreenResize(int width, int height) {
	currentScene->getCamera()->updateScreenSize(width, height);
}
