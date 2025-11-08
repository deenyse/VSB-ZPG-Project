 #include "Scene_2.h"


#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include "../Light/PointLight.h"
#include "Shader/StructShaderSources.h"


Scene_2::Scene_2() {
	lightManager->addLight(new PointLight(glm::vec3(-1.f, 2.f, 0.f), glm::vec3(1.f, 1.f, 1.f)));

	addObject(new DrawableObject("Models/formula1.obj", getCamera(), ShaderSources::Phong, lightManager))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(0.05f)))
		;
}

