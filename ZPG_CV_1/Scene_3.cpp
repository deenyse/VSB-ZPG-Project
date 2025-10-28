#include "Scene_3.h"

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

//Models
#include "./Models/bushes.h" // 8730 || bushes

#include "./Models/tree.h"// 92814 || tree
#include "./Models/plain.h"// 6 || house

//Transformations
#include "Scale.h"
#include "Translate.h"
#include "Rotate.h"

Scene_3::Scene_3() {
	// Add initialization code specific to Scene_3 here
	light->setPosition(glm::vec3(0.f, 10.f, 0.f));
	
	/*for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			addObject(tree, 92814, ShaderSources::Phong, light)
				->getTransformations()
				->addTransform(new Scale(glm::vec3(0.1f)))
				->addTransform(new Translate(glm::vec3(5.f * i, 0, 5.f * j)));
		}
	}
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			addObject(bushes, 8730, ShaderSources::Phong, light)
				->getTransformations()
				->addTransform(new Scale(glm::vec3(0.1f)))
				->addTransform(new Translate(glm::vec3(4.5f * i, 0, 4.5f * j)));
		}
	}

	addObject(plain, 6, ShaderSources::Phong, light)
		->getTransformations()
		->addTransform(new Scale(glm::vec3(70.f)));*/

}
