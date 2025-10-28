#include "Scene.h"

void Scene::initScene() {
	initLights();
	initObjects();
}

DrawableObject* Scene::addObject(DrawableObject * object) {
	objects.push_back(object);
	return object;
}

Light* Scene::addLight(Light* light) {
	if (lights.size() >= MAX_LIGHTS) {
		std::cerr << "Cannot add more lights, maximum reached: " << MAX_LIGHTS << std::endl;
		delete light;
		return nullptr;
	}
	lights.push_back(light);
	return light;
}

void Scene::renderAll() {
	for (auto obj : objects) { 
		obj->draw();
	}						    
} 

