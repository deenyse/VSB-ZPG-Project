#include "Scene_1.h"

#include "Models/sphere.h"

#include "Scale.h"
#include "Translate.h"


#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective



Scene_1::Scene_1() {
	// Add initialization code specific to Scene_1 here
	addObject(
		(new DrawableObject(sphere, 2880))
		->addTransformation(new Scale(glm::vec3(0.5, 0.5, 0.5)))
		->addTransformation(new Translate(glm::vec3(1.f, 1.f, 1)))
	);

	addObject(
		(new DrawableObject(sphere, 2880))
		->addTransformation(new Scale(glm::vec3(0.5, 0.5, 0.5)))
		->addTransformation(new Translate(glm::vec3(-1.f, 1.f, 1)))
	);

	addObject(
		(new DrawableObject(sphere, 2880))
		->addTransformation(new Scale(glm::vec3(0.5, 0.5, 0.5)))
		->addTransformation(new Translate(glm::vec3(1.f, -1.f, 1)))
	);

	addObject(
		(new DrawableObject(sphere, 2880))
		->addTransformation(new Scale(glm::vec3(0.5, 0.5, 0.5)))
		->addTransformation(new Translate(glm::vec3(-1.f, -1.f, 1)))
	);
}