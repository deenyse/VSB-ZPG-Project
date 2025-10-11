#include "Scene.h"


DrawableObject* Scene::addObject(DrawableObject* object) {
	objects.push_back(object);
	
	return object;
}

void Scene::renderAll() {
	for (auto obj : objects) { 
		obj->draw();
	}						    
} 