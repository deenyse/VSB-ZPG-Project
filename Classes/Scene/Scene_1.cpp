#include "Scene_1.h"

#include "../Model/Models.h"
#include "../Transformation/CustomTransform.h"
#include "Model/ModelLoader.h"
#include "Shader/ShaderFactory.h"
#include "Texture/Textures.h"
#include "../Model/Models.h"
Scene_1::Scene_1() {
	// //FOREST SCENE
	// for (int i = 0; i < 15; i++) {
	// 	for (int j = 0; j < 10; j++) {
	// 		addObject(
	// 			new DrawableObject(
	// 				ModelSources::Tree,
	// 				ShaderType::Phong,
	// 				new Texture(glm::vec3(0, 1, 1)),
	// 				Materials::Wood
	// 			)
	// 		)->getTransformations()
	// 			->addTransform(new Scale(glm::vec3(0.1f)))
	// 			->addTransform(new Translate(glm::vec3(5.f * i, 0, 5.f * j)));
	// 	}
	// }
	// addObject(new DrawableObject(ModelSources::Plain,  ShaderType::Phong, new Texture("../Models/grass.png"), Materials::Wood))
	// 	->getTransformations()
	// 	->addTransform(new Scale(glm::vec3(50.f)))
	// 	;
	//
	// addObject(new Skydome(ModelSources::Sky, new Texture("Models/skydome.png"), camera));
	//
	// FollowingLight* l1 = new FollowingLight(glm::vec3(1.f), 1.f, 0.0001f, 0.0005f);
	// lightManager->addLight(l1);
	//
	// DrawableObject* o1 = addObject(
	// 	new DrawableObject(
	// 		ModelSources::Sphere,
	// 		ShaderType::Constant,
	// 		new Texture(glm::vec3(1.f))
	// 	)
	// );
	//
	// o1->getTransformations()
	// 	->addTransform(new Translate(glm::vec3(0.f, 2.f, 0)))
	// 	->addTransform(new RandomTranslation(0.1f, 2.f))
	// 	->addTransform(new Scale(glm::vec3(0.2f)))
	// ;
	// l1->follow(o1);
	//
	// FollowingLight* l2 = new FollowingLight(glm::vec3(1.f), 1.f, 0.0001f, 0.0005f);
	// lightManager->addLight(l2);
	//
	// DrawableObject* o2 = addObject(
	// 	new DrawableObject(
	// 		ModelSources::Sphere,
	// 		ShaderType::Constant,
	// 		new Texture(glm::vec3(0.f,1.f,0.f))
	// 	)
	// );
	//
	// o2->getTransformations()
	// 	->addTransform(new Translate(glm::vec3(5.f, 0.5f, 5.f)))
	// 	->addTransform(new RandomTranslation(0.01f, 0.3f))
	// 	->addTransform(new Scale(glm::vec3(0.05f)))
	// ;
	// l2->follow(o2);
	//

	addLight(new PointLight(
	glm::vec3(-1.f, 3.f, 2.f),   // pos
	glm::vec3(1.f),    // light white
	1.f, 0.02f, 0.05f             // less attenuation
	));

	addLight(new DirectionalLight(glm::vec3(0.f, -2.f, 1.f), glm::vec3(1.f)));

	auto s = new Skydome(
		Models::Sky,
		Textures::Skydome,
		Materials::Skydome,
		camera);
	s->setAmbientIntensity(0.4f);
	addObject(s);


	addObject(new DrawableObject(
		Models::Plain,
		ShaderType::Blinn,
		Textures::Grass,
		Materials::Wood)
	)
	->getTransformations()
	->addTransform(new Scale(glm::vec3(50.f)))
	;

	// auto customTransformMat = glm::mat4(1.0f);
	// customTransformMat[3][3] = 20.f;
	// addObject(new DrawableObject(ModelSources::Shrek, ShaderType::Blinn, new TextureInstance("../Models/shrek.png"), Materials::Wood))
	// 	->getTransformations()
	// 	// ->addTransform(new CustomTransform(customTransformMat))
	// 	;


}
