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
	// Add initialization code specific to Scene_1 here
	
	addObject(
		(new DrawableObject(suziFlat, 2904))
		->addTransformation(new Scale(glm::vec3(0.2f, 0.2f, 0.2f)))
		->addTransformation(new Rotate(glm::radians(195.f), glm::vec3(0.0f, 1.0f, 0.0f)))
		->addTransformation(new Translate(glm::vec3(4.0f, 3.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(tree, 92814))
		->addTransformation(new Scale(glm::vec3(0.1f, 0.1f, 0.1f)))
		->addTransformation(new Rotate(glm::radians(90.f), glm::vec3(0.0f, 1.0f, 0.0f)))
		->addTransformation(new Translate(glm::vec3(0.0f, -10.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(tree, 92814))
		->addTransformation(new Scale(glm::vec3(0.2f, 0.2f, 0.2f)))
		->addTransformation(new Rotate(glm::radians(0.f), glm::vec3(0.0f, 1.0f, 0.0f)))
		->addTransformation(new Translate(glm::vec3(-2.0f, -5.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(tree, 92814))
		->addTransformation(new Scale(glm::vec3(0.1f, 0.1f, 0.1f)))
		->addTransformation(new Rotate(glm::radians(45.f), glm::vec3(0.0f, 1.0f, 0.0f)))
		->addTransformation(new Translate(glm::vec3(6.0f, -10.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(tree, 92814))
		->addTransformation(new Scale(glm::vec3(0.1f, 0.1f, 0.1f)))
		->addTransformation(new Translate(glm::vec3(8.0f, -10.0f, 0.0f)))
	);

	addObject(
	(new DrawableObject(bushes, 8730))
		->addTransformation(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)))
		->addTransformation(new Rotate(glm::radians(45.f), glm::vec3(0.0f, 1.0f, 0.0f)))
		->addTransformation(new Translate(glm::vec3(-1.f, -2.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(bushes, 8730))
		->addTransformation(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)))
		->addTransformation(new Rotate(glm::radians(90.f), glm::vec3(0.0f, 1.0f, 0.0f)))
		->addTransformation(new Translate(glm::vec3(1.0f, -2.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(bushes, 8730))
		->addTransformation(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)))
		->addTransformation(new Rotate(glm::radians(-45.f), glm::vec3(0.0f, 1.0f, 0.0f)))
		->addTransformation(new Translate(glm::vec3(2.0f, -2.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(bushes, 8730))
		->addTransformation(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)))
		->addTransformation(new Translate(glm::vec3(-1.5f, -2.0f, 0.0f)))
	);
	
	addObject(
		(new DrawableObject(bushes, 8730))
		->addTransformation(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)))
		->addTransformation(new Translate(glm::vec3(1.9f, -2.0f, 0.0f)))
	);
	
	addObject(
		(new DrawableObject(bushes, 8730))
		->addTransformation(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)))
		->addTransformation(new Translate(glm::vec3(2.2f, -2.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(bushes, 8730))
		->addTransformation(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)))
		->addTransformation(new Translate(glm::vec3(1.2f, -2.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(bushes, 8730))
		->addTransformation(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)))
		->addTransformation(new Translate(glm::vec3(0.3f, -2.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(bushes, 8730))
		->addTransformation(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)))
		->addTransformation(new Translate(glm::vec3(0.7f, -2.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(bushes, 8730))
		->addTransformation(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)))
		->addTransformation(new Translate(glm::vec3(0.7f, -2.0f, 0.0f)))
	);

	addObject(
		(new DrawableObject(gift, 66624))
		->addTransformation(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)))
		->addTransformation(new Rotate(glm::radians(110.f), glm::vec3(0.0f, 1.0f, 0.0f)))
		->addTransformation(new Rotate(glm::radians(40.f), glm::vec3(1.0f, 0.0f, 0.0f)))
		->addTransformation(new Rotate(glm::radians(-40.f), glm::vec3(0.0f, 0.0f, 1.0f)))
	);

	addObject(
		(new DrawableObject(gift, 66624))
		->addTransformation(new Rotate(glm::radians(110.f), glm::vec3(0.0f, 1.0f, 0.0f)))
		->addTransformation(new Translate(glm::vec3(0.4f, 0.4f, 0.0f)))
	);

	addObject(
		(new DrawableObject(gift, 66624))
		->addTransformation(new Scale(glm::vec3(0.4f, 0.4f, 0.4f)))
		->addTransformation(new Rotate(glm::radians(110.f), glm::vec3(0.0f, 1.0f, 0.0f)))
		->addTransformation(new Rotate(glm::radians(40.f), glm::vec3(1.0f, 0.0f, 0.0f)))
		->addTransformation(new Translate(glm::vec3(-1.4f, 0.4f, 0.0f)))

	);
	
	addObject(
	(new DrawableObject(sphere, 2880))
		->addTransformation(new Scale(glm::vec3(0.3f, 0.3f, 0.3f)))
		->addTransformation(new Rotate(glm::radians(25.f), glm::vec3(1.0f, 0.0f, 0.0f)))
		->addTransformation(new Translate(glm::vec3(-1.0f, -3.0f, 2.0f)))
	);

	addObject(
		(new DrawableObject(sphere, 2880))
		->addTransformation(new Scale(glm::vec3(0.2f, 0.2f, 0.2f)))
		->addTransformation(new Rotate(glm::radians(25.f), glm::vec3(1.0f, 0.0f, 1.0f)))
		->addTransformation(new Translate(glm::vec3(5.0f, 3.0f, 0.0f)))
	);

	addObject(
	(new DrawableObject(suziFlat, 2904))
		->addTransformation(new Scale(glm::vec3(0.4f, 0.4f, 0.4f)))
		->addTransformation(new Rotate(glm::radians(165.f), glm::vec3(0.0f, 1.0f, 0.0f)))
		->addTransformation(new Translate(glm::vec3(-1.3f, -0.5f, 0.0f)))
	);
	

	
}
