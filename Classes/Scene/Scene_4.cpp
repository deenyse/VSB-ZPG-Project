#include "Scene_4.h"

#include "Texture/Textures.h"
#include "../Light/DirectionalLight.h"
Scene_4::Scene_4() {
    //FOREST SCENE
	addObject(new Skydome(Models::Sky, Textures::Skydome, Materials::Skydome,camera));
	addLight(new DirectionalLight(glm::vec3(10.f, 15.f, 10.f), glm::vec3(1.0f, 0.95f, 0.8f)));
    for (int i = 0; i < 15; i++) {
    	for (int j = 0; j < 10; j++) {
    		addObject(
    			new DrawableObject(
    				Models::Tree,
    				ShaderType::Phong,
    				Textures::Green,
    				Materials::Wood
    			)
    		)->getTransformations()
    			->addTransform(new Scale(glm::vec3(0.3f)))
    			->addTransform(new Translate(glm::vec3(5.f * i, 0, 5.f * j)));
    	}
    }
    addObject(new DrawableObject(Models::Plain,  ShaderType::Phong, Textures::Grass, Materials::Wood))
    	->getTransformations()
    	->addTransform(new Scale(glm::vec3(50.f)))
    	;



    FollowingLight* l1 = new FollowingLight(glm::vec3(1.f), 0.7f, 0.02f, 0.5f);
    addLight(l1);

    DrawableObject* o1 = addObject(
    	new DrawableObject(
    		Models::Sphere,
    		ShaderType::Constant,
    		Textures::White,
    		Materials::Constant
    	)
    );

    o1->getTransformations()
    	->addTransform(new Translate(glm::vec3(0.f, 1.f, 0)))
    	->addTransform(new RandomTranslation(2.f, 2.f))
    	->addTransform(new Scale(glm::vec3(0.06f)))
    ;
    l1->follow(o1);



    FollowingLight* l2 = new FollowingLight(glm::vec3(1.f), 0.7f, 0.01f, 0.5f);
    addLight(l2);

    DrawableObject* o2 = addObject(
    	new DrawableObject(
    		Models::Sphere,
    		ShaderType::Constant,
    		Textures::White,
    		Materials::Constant
    	)
    );

    o2->getTransformations()
    	->addTransform(new Translate(glm::vec3(20.f, 1.0f, 13.f)))
    	->addTransform(new RandomTranslation(2.f, 2.f))
    	->addTransform(new Scale(glm::vec3(0.05f)))
    ;
    l2->follow(o2);


	addObject(new DrawableObject(
		Models::Shrek,
		ShaderType::Phong,
		Textures::Shrek,
		Materials::Metal
	))
	->getTransformations()
	->addTransform(new Translate(glm::vec3(1.f, 0.f, -2.f)))
	;

	addObject(new DrawableObject(
		Models::Fiona,
		ShaderType::Phong,
		Textures::Fiona,
		Materials::Plastic
	))
	->getTransformations()
	->addTransform(new Translate(glm::vec3(-1.f, 0.f, -2.f)))
	;
	addObject(new DrawableObject(
		Models::Toiled,
		ShaderType::Phong,
		Textures::Toiled,
		Materials::Wood
	))
	->getTransformations()
	->addTransform(new Translate(glm::vec3(3.f, 0.f, -2.f)))
	;
}
