#include "Scene_1.h"

#include "Models/sphere.h"

#include "Scale.h"
#include "Translate.h"


#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective



Scene_1::Scene_1() {
	// Add initialization code specific to Scene_1 here

	addObject(sphere, 2880, ShaderSources::Phong)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(2.f, 0.f, 0)));


	addObject(sphere, 2880, ShaderSources::Phong)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(-2.f, 0.f, 0)));
	
	addObject(sphere, 2880, ShaderSources::Phong)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(0, 2.f, 0)));

	addObject(sphere, 2880, ShaderSources::Phong)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(0, -2.f, 0)));
	
}