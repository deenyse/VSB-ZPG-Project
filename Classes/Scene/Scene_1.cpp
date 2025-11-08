#include "Scene_1.h"

#include "Shader/StructShaderSources.h"
#include "../Model/StructModelSources.h"
Scene_1::Scene_1() {
	lightManager->addLight(new PointLight(glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f)));

	DrawableObject* o = new DrawableObject(ModelSources::Sphere, getCamera(), ShaderSources::Phong, lightManager);
	addObject(o)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(2.f, 0.f, 0)));


	addObject(new DrawableObject(ModelSources::Sphere, getCamera(), ShaderSources::Phong, lightManager))
		->getTransformations()
		->addTransform(new Translate(glm::vec3(-2.f, 0.f, 0)));

	addObject(new DrawableObject(ModelSources::Sphere, getCamera(), ShaderSources::Phong, lightManager))
		->getTransformations()
		->addTransform(new Translate(glm::vec3(0, 2.f, 0)));

	addObject(new DrawableObject(ModelSources::Sphere, getCamera(), ShaderSources::Phong, lightManager))
		->getTransformations()
		->addTransform(new Translate(glm::vec3(0, -2.f, 0)));
}