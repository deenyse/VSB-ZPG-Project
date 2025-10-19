 #include "Scene_2.h"

#include "Models/sphere.h"

#include "Scale.h"
#include "Translate.h"
#include "Rotate.h"
#include "DynamicRotation.h"

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective



Scene_2::Scene_2() {
	//light = new Light(glm::vec3(5.f, 100.f, 2.f));
	light->setPosition(glm::vec3(0.f, 10.f, 0.f));



	addObject(sphere, 2880, ShaderSources::Phong, light)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(0.f, -10.f, 0.f)))
		->addTransform(new Scale(glm::vec3(2.f)))
		->addTransform(new DynamicRotation(0.005f, glm::vec3(0, 1, 0)));


	addObject(sphere, 2880, ShaderSources::Phong, light)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(0.f, -10.f, 0.f)))
		->addTransform(new DynamicRotation(0.01f, glm::vec3(0, 1, 0))) // rotation around sun
		->addTransform(new Translate(glm::vec3(0.f, 0.f, 7.f))) // distance from sun
		->addTransform(new DynamicRotation(0.05f, glm::vec3(0, 1, 0))) // own axis
		;

	addObject(sphere, 2880, ShaderSources::Phong, light)
		->getTransformations()
		->addTransform(new Translate(glm::vec3(0.f, -10.f, 0.f)))
		->addTransform(new Scale(glm::vec3(0.5f)))
		->addTransform(new DynamicRotation(0.01f, glm::vec3(0, 1, 0)))
		->addTransform(new Translate(glm::vec3(0.f, 0.f, 14.f)))//distance from sun ||2x Earth

		->addTransform(new DynamicRotation(0.05f, glm::vec3(0, 1, 0)))//rotation around earth
		->addTransform(new Translate(glm::vec3(0.f, 0.f, 4.f)))//distance from earth

		->addTransform(new DynamicRotation(0.05f, glm::vec3(0, 1, 0))) //own axis



		;

}
