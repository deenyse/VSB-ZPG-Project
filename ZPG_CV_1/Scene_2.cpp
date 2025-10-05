#include "Scene_2.h"


//#include "Models/sphere.h"

#include "Scale.h"
#include "Translate.h"
#include "Rotate.h"

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

const float points[18] = {
-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // brm l
 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // btm r
 0.0f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f  // top
};

Scene_2::Scene_2() {
	// Add initialization code specific to Scene_1 here
	
	addObject(
		(new DrawableObject(points, 3))
		->addTransformation(new Scale(glm::vec3(1.2f, 1.2f, 1.f)))
		->addTransformation(new Rotate(glm::radians(90.f), glm::vec3(0.0f, 0.0f, 1.0f)))
		//->addTransformation(new Translate(glm::vec3(-0.5f, 0.0f, 0.0f)))
	);
}
