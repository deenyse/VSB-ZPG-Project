#include "Scene_1.h"

void Scene_1::initLights() {
	//addLight(new PointLight(glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f)));
	//

	//// Spot light above the scene, pointing down
	//addLight(new SpotLight(
	//	glm::vec3(5.f, 10.f, 0.f),           // position
	//	glm::vec3(0.f, -1.f, 0.f),           // direction
	//	glm::vec3(1.f, 0.8f, 0.6f),          // color
	//	glm::cos(glm::radians(12.5f)),       // cutOff (inner angle)
	//	glm::cos(glm::radians(17.5f))        // outerCutOff (outer angle)
	//));

	//addLight(new DirectionalLight(
	//	glm::vec3(-0.2f, -1.0f, -0.3f),      // direction
	//	glm::vec3(0.5f, 0.5f, 0.5f)          // color
	//));

	addLight(new HeadLight(getCamera()));
}

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

