#include "Scene_1.h"



void Scene_1::initObjects() {
	addObject(new DrawableObject(sphere, 2880, getCamera(), ShaderSources::Phong, getLights()))
		->getTransformations()
		->addTransform(new Translate(glm::vec3(2.f, 0.f, 0)));


	addObject(new DrawableObject(sphere, 2880, getCamera(), ShaderSources::Phong, getLights()))
		->getTransformations()
		->addTransform(new Translate(glm::vec3(-2.f, 0.f, 0)));

	addObject(new DrawableObject(sphere, 2880, getCamera(), ShaderSources::Phong, getLights()))
		->getTransformations()
		->addTransform(new Translate(glm::vec3(0, 2.f, 0)));

	addObject(new DrawableObject(sphere, 2880, getCamera(), ShaderSources::Phong, getLights()))
		->getTransformations()
		->addTransform(new Translate(glm::vec3(0, -2.f, 0)));
}

void Scene_1::initLights() {
	addLight(new Light(glm::vec3(0.f, 0.f, 0.f)));
}