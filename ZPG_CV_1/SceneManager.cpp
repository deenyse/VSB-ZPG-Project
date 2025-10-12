#include "SceneManager.h"


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
}

void SceneManager::handleScreenResize(int width, int height) {
	currentScene->getCamera()->updateScreenSize(width, height);
}
