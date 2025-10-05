#include "Scene.h"


void Scene::addObject(DrawableObject* object) {
	objects.push_back(object);
}

void Scene::renderAll() {
	for (auto obj : objects) { 
		obj->draw();
	}						    
} 