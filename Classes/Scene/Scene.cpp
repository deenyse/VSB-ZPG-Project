#include "Scene.h"

Scene::Scene() {
	lightManager->addLight(headLight);
}

void Scene::switchHeadLight() {
	headLight->isOn = !headLight->isOn;
	headLight->notify(ObservableSubjects::SLight);
}

DrawableObject* Scene::addObject(DrawableObject * object) {
	if (dynamic_cast<Skydome*>(object)) {
		skydome = dynamic_cast<Skydome*>(object);
		return skydome;
	}
	objects.push_back(object);
	return object;
}



void Scene::renderAll() {
	if (skydome) {
		skydome->draw();
		glClear(GL_DEPTH_BUFFER_BIT);
	}
	for (auto obj : objects)
		obj->draw();
}

