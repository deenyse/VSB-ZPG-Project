#include "Scene_3.h"

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective


#include "../Model/StructModelSources.h"
#include "Transformation/CustomTransform.h"
#include "Transformation/DynamicRotation.h"

Scene_3::Scene_3() {
	lightManager->addLight(new PointLight(
		glm::vec3(-1.f, 10.f, -2.f),   // pos
		glm::vec3(10.f),    // light white
		1.f, 0.02f, 0.05f             // less attenuation
	));

	addObject(new Skydome(ModelSources::Sky, new Texture("Models/skydome.png"), camera));

	addObject(new DrawableObject(ModelSources::Plain,  ShaderType::Phong, new Texture("../Models/grass.png"), Materials::Wood))
	->getTransformations()
	->addTransform(new Scale(glm::vec3(50.f)))
	;

	auto customTransformMat = glm::mat4(1.0f);
	customTransformMat[3][3] = 20.f;

	addObject(new DrawableObject(ModelSources::SteamMachine, ShaderType::Constant, new Texture(glm::vec3(0.5f))))
		->getTransformations()
		// ->addTransform(new CustomTransform(customTransformMat))
		;



}

void Scene_3::onObjectSelect(GLuint id) {
	for (auto& [shaderType, objs] : objects) {
		for (auto o : objs) {
			if (o->getID() == id) {
				// selectedObject = o;
			}
		}
	}
}


