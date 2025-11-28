#include "Scene_1.h"

#include "../Model/Models.h"
#include "../Transformation/CustomTransform.h"
#include "Model/ModelLoader.h"
#include "Shader/ShaderFactory.h"
#include "Texture/Textures.h"
#include "../Model/Models.h"
Scene_1::Scene_1() {

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


	addObject(new DrawableObject(Models::Shrek, ShaderType::Blinn,Textures::Shrek, Materials::Wood))
		->getTransformations()
		;


}
