#include "SceneManager.h"

SceneManager::SceneManager() {
	addScene(new Scene_1());
	addScene(new Scene_2());
	addScene(new Scene_3());


	if (!scenes.empty()) currentScene = scenes[0];
}

void SceneManager::addScene(Scene* scene) 
{ 
	scenes.push_back(scene); 
}

void SceneManager::setScene(int id)
{
	if (id >= 0 && id < scenes.size()) currentScene = scenes[id];
}

void SceneManager::renderCurrentScene() 
{
	if (currentScene) currentScene->renderAll(); 
}

void SceneManager::handleMouseMovement(float deltaX, float deltaY) 
{
	if (currentScene) currentScene->getCamera()->updateOrientation(deltaX, deltaY); 
}


void SceneManager::moveCamera(int direction) {
	if (!direction) return;
	if (direction & Direction::Forward) currentScene->getCamera()->forward();
	if (direction & Direction::Backward) currentScene->getCamera()->backward();
	if (direction & Direction::Left) currentScene->getCamera()->left();
	if (direction & Direction::Right) currentScene->getCamera()->right();
}

void SceneManager::switchHeadLight() {
	currentScene->switchHeadLight();
}

void SceneManager::handleScreenResize(int width, int height) {
	for (auto scene : scenes)
		scene->getCamera()->updateScreenSize(width, height);
}
