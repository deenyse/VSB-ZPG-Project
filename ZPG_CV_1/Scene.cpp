#include "Scene.h"


DrawableObject* Scene::addObject(const float* points, int verticiesNum) {
	DrawableObject* object = new DrawableObject(points, verticiesNum, camera);
	objects.push_back(object);
	return object;
}

void Scene::renderAll() {
	for (auto obj : objects) { 
		obj->draw();
	}						    
} 