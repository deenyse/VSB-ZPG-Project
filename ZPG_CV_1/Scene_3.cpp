#include "Scene_3.h"

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

//Models
#include "./Models/bushes.h" // 8730 || bushes
#include "./Models/gift.h" // 66624 || gift
#include "./Models/sphere.h"// 2880 || sphere
#include "./Models/suzi_flat.h"// 2904 || suziFlat
#include "./Models/tree.h"// 92814 || tree

//Transformations
#include "Scale.h"
#include "Translate.h"
#include "Rotate.h"

Scene_3::Scene_3() {
	// Add initialization code specific to Scene_3 here

	addObject(new DrawableObject(suziFlat, 2904))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.2f)))
		->addTransform(new Rotate(glm::radians(195.f), glm::vec3(0.f, 1.f, 0.f)))
		->addTransform(new Translate(glm::vec3(4.f, 3.f, 0.f)));

	addObject(new DrawableObject(tree, 92814))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.1f)))
		->addTransform(new Rotate(glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f)))
		->addTransform(new Translate(glm::vec3(0.f, -10.f, 0.f)));

	addObject(new DrawableObject(tree, 92814))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.2f)))
		->addTransform(new Translate(glm::vec3(-2.f, -5.f, 0.f)));

	addObject(new DrawableObject(tree, 92814))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.1f)))
		->addTransform(new Rotate(glm::radians(45.f), glm::vec3(0.f, 1.f, 0.f)))
		->addTransform(new Translate(glm::vec3(6.f, -10.f, 0.f)));

	addObject(new DrawableObject(tree, 92814))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.1f)))
		->addTransform(new Translate(glm::vec3(8.f, -10.f, 0.f)));

	// Bushes
	addObject(new DrawableObject(bushes, 8730))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5f)))
		->addTransform(new Rotate(glm::radians(45.f), glm::vec3(0.f, 1.f, 0.f)))
		->addTransform(new Translate(glm::vec3(-1.f, -2.f, 0.f)));

	addObject(new DrawableObject(bushes, 8730))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5f)))
		->addTransform(new Rotate(glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f)))
		->addTransform(new Translate(glm::vec3(1.f, -2.f, 0.f)));

	addObject(new DrawableObject(bushes, 8730))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5f)))
		->addTransform(new Rotate(glm::radians(-45.f), glm::vec3(0.f, 1.f, 0.f)))
		->addTransform(new Translate(glm::vec3(2.f, -2.f, 0.f)));

	addObject(new DrawableObject(bushes, 8730))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5f)))
		->addTransform(new Translate(glm::vec3(-1.5f, -2.f, 0.f)));

	addObject(new DrawableObject(bushes, 8730))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5f)))
		->addTransform(new Translate(glm::vec3(1.9f, -2.f, 0.f)));

	addObject(new DrawableObject(bushes, 8730))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5f)))
		->addTransform(new Translate(glm::vec3(2.2f, -2.f, 0.f)));

	addObject(new DrawableObject(bushes, 8730))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5f)))
		->addTransform(new Translate(glm::vec3(1.2f, -2.f, 0.f)));

	addObject(new DrawableObject(bushes, 8730))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5f)))
		->addTransform(new Translate(glm::vec3(0.3f, -2.f, 0.f)));

	addObject(new DrawableObject(bushes, 8730))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5f)))
		->addTransform(new Translate(glm::vec3(0.7f, -2.f, 0.f)));

	// Gifts
	addObject(new DrawableObject(gift, 66624))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.5f)))
		->addTransform(new Rotate(glm::radians(110.f), glm::vec3(0.f, 1.f, 0.f)))
		->addTransform(new Rotate(glm::radians(40.f), glm::vec3(1.f, 0.f, 0.f)))
		->addTransform(new Rotate(glm::radians(-40.f), glm::vec3(0.f, 0.f, 1.f)));

	addObject(new DrawableObject(gift, 66624))
		->getTransformations()
		->addTransform(new Rotate(glm::radians(110.f), glm::vec3(0.f, 1.f, 0.f)))
		->addTransform(new Translate(glm::vec3(0.4f, 0.4f, 0.f)));

	addObject(new DrawableObject(gift, 66624))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.4f)))
		->addTransform(new Rotate(glm::radians(110.f), glm::vec3(0.f, 1.f, 0.f)))
		->addTransform(new Rotate(glm::radians(40.f), glm::vec3(1.f, 0.f, 0.f)))
		->addTransform(new Translate(glm::vec3(-1.4f, 0.4f, 0.f)));

	// Spheres
	addObject(new DrawableObject(sphere, 2880))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.3f)))
		->addTransform(new Rotate(glm::radians(25.f), glm::vec3(1.f, 0.f, 0.f)))
		->addTransform(new Translate(glm::vec3(-1.f, -3.f, 2.f)));

	addObject(new DrawableObject(sphere, 2880))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.2f)))
		->addTransform(new Rotate(glm::radians(25.f), glm::vec3(1.f, 0.f, 1.f)))
		->addTransform(new Translate(glm::vec3(5.f, 3.f, 0.f)));

	// Suzi
	addObject(new DrawableObject(suziFlat, 2904))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.4f)))
		->addTransform(new Rotate(glm::radians(165.f), glm::vec3(0.f, 1.f, 0.f)))
		->addTransform(new Translate(glm::vec3(-1.3f, -0.5f, 0.f)));
}
