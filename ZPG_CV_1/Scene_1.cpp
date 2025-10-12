#include "Scene_1.h"

#include "Models/sphere.h"

#include "Scale.h"
#include "Translate.h"


#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective



Scene_1::Scene_1() {
	// Add initialization code specific to Scene_1 here

	addObject(sphere, 2880);
		/*->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5, 0.5, 0.5)))
		->addTransform(new Translate(glm::vec3(1.f, 1.f, 1)));


	addObject(sphere, 2880)
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5, 0.5, 0.5)))
		->addTransform(new Translate(glm::vec3(-1.f, 1.f, 1)));
	
	addObject(sphere, 2880)
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5, 0.5, 0.5)))
		->addTransform(new Translate(glm::vec3(1.f, -1.f, 1)));

	addObject(sphere, 2880)
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5, 0.5, 0.5)))
		->addTransform(new Translate(glm::vec3(-1.f, -1.f, 1)));*/
	
}