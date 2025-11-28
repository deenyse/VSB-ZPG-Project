#include "Scene_1.h"

#include "../Model/Models.h"
#include "../Transformation/CustomTransform.h"
#include "Model/ModelLoader.h"
#include "Shader/ShaderFactory.h"
#include "Texture/Textures.h"
#include "../Model/Models.h"
Scene_1::Scene_1() {

	addLight(new PointLight(
	glm::vec3(-1.f, 3.f, 2.f),
	glm::vec3(1.f),
	1.f, 0.02f, 0.05f
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

	bT = new BezierTranslation(0.5f, glm::vec3(0.f, 1.f, 0.f));

	addObject(new DrawableObject(
		Models::Formula1,
		ShaderType::Blinn,
		Textures::Yellow,
		Materials::Metal
	))
	->getTransformations()
	->addTransform(bT)
	->addTransform(new Rotate(-90.f, glm::vec3(0.f, 1.f, 0.f)))
	->addTransform(new Scale(glm::vec3(0.05f)))
	;

	addObject(new DrawableObject(Models::SteamMachine, ShaderType::Blinn,Textures::Black, Materials::Wood))
		->getTransformations()
		->addTransform(new Rotate(90.f, glm::vec3(0.f, 1.f, 0.f)));
		;


}

void Scene_1::onPositionUpdateAction(glm::vec3 position) {
	if (bT)
		bT->addPoint(position);
}
