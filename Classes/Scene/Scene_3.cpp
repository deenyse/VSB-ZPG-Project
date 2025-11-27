#include "Scene_3.h"

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective


#include "../Model/StructModelSources.h"
#include "Transformation/CustomTransform.h"
#include "Transformation/DynamicRotation.h"


Scene_3::Scene_3() {
	yellow = new TextureInstance(glm::vec3(1.f, 1.f, 0.f));
	red    = new TextureInstance(glm::vec3(1.f, 0.f, 0.f));

	addLight(new PointLight(
		glm::vec3(-1.f, 10.f, -2.f),   // pos
		glm::vec3(10.f),    // light white
		1.f, 0.02f, 0.05f             // less attenuation
	));

	// addObject(new Skydome(ModelSources::Sky, new Texture("Models/skydome.png"), camera));

	//
	// auto o  =new DrawableObject(ModelSources::Sphere, ShaderType::Blinn, red);
	// highValueBalls.push_back(o->getID());
	// addObject(o)
	// 	->getTransformations()
	// 	->addTransform(new RandomTranslation(10.f, 1.2f))
	// 	->addTransform(new Scale(glm::vec3(0.5f)))
	// 	;
	// for (int i =0; i < 3; i++)
	// addObject(new DrawableObject(ModelSources::Sphere, ShaderType::Blinn, yellow))
	// 	->getTransformations()
	// 	->addTransform(new RandomTranslation(10.f, 0.8))
	// 	->addTransform(new Scale(glm::vec3(0.5f)));
	// 	;


}

void Scene_3::spawnNewBall() {
	int chance = std::rand() % 100;

	// if (chance < 20) {
	// 	auto o  =new DrawableObject(ModelSources::Sphere, ShaderType::Blinn, red);
	// 	highValueBalls.push_back(o->getID());
	// 	addObject(o)
	// 		->getTransformations()
	// 		->addTransform(new RandomTranslation(10.f, 1.2f))
	// 		->addTransform(new Scale(glm::vec3(0.5f)));
	// } else {
	// 	addObject(new DrawableObject(ModelSources::Sphere, ShaderType::Blinn, yellow))
	// 		->getTransformations()
	// 		->addTransform(new RandomTranslation(10.f, 0.8))
	// 		->addTransform(new Scale(glm::vec3(0.5f)));
	// }
}


void Scene_3::onObjectSelect(GLuint id) {
	if (!id)
		return;

	for (auto& [shaderType, objs] : objects) {
		for (size_t i = 0; i < objs.size(); ++i) {
			auto oid = objs[i]->getID();
			if (oid == id) {
				for (size_t j = 0; j < highValueBalls.size(); ++j) {
					if (oid == highValueBalls[j]) {
						highValueBalls.erase(highValueBalls.begin() + j);
						points += 4;
						printf("High score ball cached!\n");
						break;
					}
				}
				delete objs[i];        // free memory
				objs.erase(objs.begin() + i);
				points += 1;
				spawnNewBall();
				printf("Score: %d\n", points);
				return;
			}
		}
	}


}


