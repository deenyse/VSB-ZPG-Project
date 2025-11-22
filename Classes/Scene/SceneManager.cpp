#include "SceneManager.h"

#include "../Application/EnumMooveDirections.h"
#include "Scene_1.h"
#include "Scene_2.h"
#include "Scene_3.h"

SceneManager::SceneManager() {
	// addScene(new Scene_1());
	addScene(new Scene_2());
	// addScene(new Scene_3());


	if (!scenes.empty())
		setScene(0);
}

void SceneManager::addScene(Scene* scene) 
{ 
	scenes.push_back(scene); 
}

void SceneManager::setScene(int id)
{
	if (id < 0 || id >= scenes.size()) return;

	currentScene = scenes[id];
	currentScene->bindCameraAndLightToUsedShaders();
}

void SceneManager::renderCurrentScene(float dt)
{
	if (currentScene) currentScene->renderAll(dt);
}

Scene* SceneManager::getCurrentScene() {
	return currentScene;
}

void SceneManager::updateCameraPosition(int direction, glm::vec2 mouseOffset, float deltaTime) {
	if (!currentScene)
		return;

	if (mouseOffset.x != 0 || mouseOffset.y != 0)
		currentScene->getCamera()->updateOrientation(mouseOffset, deltaTime);

	if (!direction) return;
	if (direction & Direction::Forward) currentScene->getCamera()->forward(deltaTime);
	if (direction & Direction::Backward) currentScene->getCamera()->backward(deltaTime);
	if (direction & Direction::Left) currentScene->getCamera()->left(deltaTime);
	if (direction & Direction::Right) currentScene->getCamera()->right(deltaTime);
}

void SceneManager::switchHeadLight() {
	currentScene->switchHeadLight();
}

void SceneManager::handleScreenResize(int width, int height) {
	for (auto scene : scenes)
		scene->getCamera()->updateScreenSize(width, height);
}
