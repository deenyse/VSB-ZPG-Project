#include "Scene_1.h"



void Scene_1::initObjects() {
	addObject(sphere, 2880, ShaderSources::Constant, light)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(2.f, 0.f, 0)));


	addObject(sphere, 2880, ShaderSources::Phong, light)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(-2.f, 0.f, 0)));

	addObject(sphere, 2880, ShaderSources::Lamb, light)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(0, 2.f, 0)));

	addObject(sphere, 2880, ShaderSources::Bling, light)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(0, -2.f, 0)));
}

void Scene_1::initLights() {
	return;
}