#include "Scene.h"

Scene::Scene() {
	lightManager->addLight(headLight);
}

void Scene::switchHeadLight() {
	headLight->isOn = !headLight->isOn;
	headLight->notify(ObservableSubjects::SLight);
}

void Scene::initScene() {
	initLights();
	initObjects();
}

DrawableObject* Scene::addObject(DrawableObject * object) {
	objects.push_back(object);
	return object;
}



void Scene::renderAll() {
	for (auto obj : objects) { 
		obj->draw();
	}						    
} 

