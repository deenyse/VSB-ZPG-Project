#include "Scene.h"


DrawableObject* Scene::addObject(const float* points, int verticiesNum, const char* const shSource[2]) {
	DrawableObject* object = new DrawableObject(points, verticiesNum, camera, shSource);
	objects.push_back(object);
	return object;
}

void Scene::renderAll() {
	for (auto obj : objects) { 
		obj->draw();
	}						    
} 