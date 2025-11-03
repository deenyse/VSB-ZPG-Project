 #include "Scene_2.h"


#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include "../Light/PointLight.h"

void Scene_2::initLights(){
	addLight(new PointLight(glm::vec3(-1.f, 2.f, 0.f), glm::vec3(1.f, 1.f, 1.f)));

}

void Scene_2::initObjects() {
	addObject(new DrawableObject("Models/formula1.obj", getCamera(), ShaderSources::Phong, getLights()))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.05f)))
		;
}
