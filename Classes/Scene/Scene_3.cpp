#include "Scene_3.h"

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective


#include "../Shader/StructShaderSources.h"
#include "../Model/StructModelSources.h"

Scene_3::Scene_3() {
	lightManager->addLight(new DirectionalLight(glm::vec3(0.f, 0.3f, -2.f), glm::vec3(1.5f)));
	lightManager->addLight(new PointLight(
		glm::vec3(-1.f, 10.f, -2.f),   // pos
		glm::vec3(20.f, 20.f, 20.f),    // light white
		1.f, 0.02f, 0.05f             // less attenuation
	));

	//
	// FollowingLight* l = new FollowingLight(glm::vec3(1.f),1.f,0.0001f,0.0005f);
	// lightManager->addLight(l);
	//
	// DrawableObject* o = new DrawableObject(ModelSources::Sphere, getCamera(), ShaderSources::Constant, lightManager);
	// addObject(o)
	// 	->getTransformations()
	// 	->addTransform(new Translate(glm::vec3(0.f, 0.5f, 0)))
	// 	->addTransform(new RandomTranslation(0.01f, 0.3f))
	// 	->addTransform(new Scale(glm::vec3(0.02f)))
	// 	;
	//
	// l->follow(o);
	//
	// l = new FollowingLight(glm::vec3(1.f), 1.f, 0.0001f, 0.0005f);
	// lightManager->addLight(l);
	//
	// o = new DrawableObject(ModelSources::Sphere, getCamera(), ShaderSources::Constant, lightManager);
	// addObject(o)
	// 	->getTransformations()
	// 	->addTransform(new Translate(glm::vec3(5.f, 0.5f, 5)))
	// 	->addTransform(new RandomTranslation(0.01f, 0.3f))
	// 	->addTransform(new Scale(glm::vec3(0.05f)))
	// 	;
	//
	// l->follow(o);
	//
	// for (int i = 0; i < 11; i++) {
	// 	for (int j = 0; j < 11; j++) {
	// 		addObject(new DrawableObject(ModelSources::Tree, getCamera(), ShaderSources::Phong, lightManager))
	// 			->getTransformations()
	// 			->addTransform(new Scale(glm::vec3(0.1f)))
	// 			->addTransform(new Translate(glm::vec3(5.f * i, 0, 5.f * j)));
	// 	}
	// }


	addObject(new DrawableObject(ModelSources::Shrek, getCamera(), ShaderSources::Phong, lightManager, new Texture("../Models/shrek.png")))

	;
	addObject(new DrawableObject(ModelSources::Fiona, getCamera(), ShaderSources::Phong, lightManager, new Texture("../Models/fiona.png")))
	->getTransformations()
	->addTransform(new Translate(glm::vec3(1.5f, 0.f, 0.f)));
	;


	addObject(new DrawableObject(ModelSources::Plain, getCamera(), ShaderSources::Constant, lightManager, new Texture("../Models/grass.png")))
		->getTransformations()
		->addTransform(new Scale(glm::vec3(50.f)))
	;


	addObject(new Skydome(ModelSources::Sky, getCamera(), new Texture("Models/skydome.png")));

}


