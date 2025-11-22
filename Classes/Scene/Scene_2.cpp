 #include "Scene_2.h"

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include "../Light/PointLight.h"
#include "Model/StructModelSources.h"
#include "../Transformation/DynamicRotation.h"
Scene_2::Scene_2() {
	// lightManager->addLight(new PointLight(glm::vec3(-1.f, 2.f, 0.f), glm::vec3(1.f, 1.f, 1.f)));

    auto sun = new DrawableObject(
        ModelSources::Planet,
        ShaderType::Constant,
        new Texture("../Models/sun_texture.jpg"), // yellow sun
        Materials::Metal
    );

    addObject(sun)
        ->getTransformations()
        ->addTransform(new Scale(glm::vec3(1.5f))) // sun is larger than planets
        ->addTransform(new DynamicRotation(0.5f, glm::vec3(0.f, 1.f, 0.f))) // Sun rotation on its axis
        ->addTransform(new Rotate(180.f, glm::vec3(0.f, 0.f, 1.f))) // texture rotation

        ;

    lightManager->addLight(new PointLight(
        glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 1.f),
        1.f, 0.0001f, 0.00005f
    ));
    auto earth = new DrawableObject(
        ModelSources::Planet,
        ShaderType::Constant,
        new Texture("../Models/earth_texture.jpg"), // blue Earth
        Materials::Metal
    );

    auto earthTransforms = addObject(earth)
        ->getTransformations();

    earthTransforms
        ->addTransform(new DynamicRotation(1.f, glm::vec3(0.f, 1.f, 0.f))) // Earth rotation on sun axis
        ->addTransform(new Translate(glm::vec3(7.f, 0.f, 0.f))) // distance from Sun
        ->addTransform(new DynamicRotation(2.f, glm::vec3(0.f, 1.f, 0.f))) // Earth rotation on its axis
        ->addTransform(new Rotate(180.f, glm::vec3(0.f, 0.f, 1.f))) // pole texture rotaton rotation
        ->addTransform(new Scale(glm::vec3(0.5f))); // scale

    auto moon = new DrawableObject(
        ModelSources::Planet,
        ShaderType::Constant,
        new Texture("../Models/moon_texture.jpg"), // grey Moon
        Materials::Metal
    );

    auto moonTransforms = addObject(moon)
        ->getTransformations();

    moonTransforms
        ->addTransform(earthTransforms)

        //Moon rotation around Earth
        ->addTransform(new DynamicRotation(-0.8f, glm::vec3(0.f, 1.f, 0.f))) //moon rotation on earth axis
        ->addTransform(new Translate(glm::vec3(2.f, 0.f, 0.f))) // distance from Earth
        ->addTransform(new DynamicRotation(-1.f, glm::vec3(0.f, 1.f, 0.f))) // Moon rotation on its axis

        ->addTransform(new Scale(glm::vec3(0.4f))); // scale last

}

