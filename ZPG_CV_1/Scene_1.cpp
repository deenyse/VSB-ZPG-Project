#include "Scene_1.h"

#include "Models/sphere.h"

#include "Scale.h"
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

//const float points[18] = {
//-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // brm l
// 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // btm r
// 0.0f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f  // top
//};

Scene_1::Scene_1() {
	// Add initialization code specific to Scene_1 here
	DrawableObject* sphereInstance = new DrawableObject(sphere, 2880);
	sphereInstance->addTransformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));
	
	addObject(sphereInstance);
}