#include "Scene_2.h"

#include "./Models/bushes.h" // 8730 || bushes

#include "./Models/tree.h"// 92814 || tree
//#include "Models/sphere.h"

#include "Scale.h"
#include "Translate.h"
#include "Rotate.h"

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective



Scene_2::Scene_2() {
	// Add initialization code specific to Scene_1 here

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			addObject(tree, 92814)
				->getTransformations()
				->addTransform(new Scale(glm::vec3(0.1f)))
				->addTransform(new Translate(glm::vec3(5.f*i, 0, 5.f*j)));
		}
	}

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			addObject(bushes, 8730)
				->getTransformations()
				->addTransform(new Scale(glm::vec3(0.1f)))
				->addTransform(new Translate(glm::vec3(4.5f * i, 0, 4.5f * j)));
		}
	}
	
	//// Bushes
	//addObject(bushes, 8730)
	//	->getTransformations()
	//	->addTransform(new Scale(glm::vec3(0.5f)))
	//	->addTransform(new Rotate(glm::radians(45.f), glm::vec3(0.f, 1.f, 0.f)))
	//	->addTransform(new Translate(glm::vec3(-1.f, -2.f, 0.f)));

}
