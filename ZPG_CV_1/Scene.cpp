#include "Scene.h"


DrawableObject* Scene::addObject(const float* points, int verticiesNum, ShaderPair shaderSource) {
	DrawableObject* object = new DrawableObject(points, verticiesNum, camera, shaderSource);
	objects.push_back(object);
	return object;
}

void Scene::renderAll() {
	for (auto obj : objects) { 
		obj->draw();
	}						    
} 