#include "Scene_5.h"
#include "../Light/PointLight.h"
#include "Model/Models.h"
#include "../Transformation/DynamicRotation.h"
#include "Texture/Textures.h"

Scene_5::Scene_5() {
    addLight(new PointLight(glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f)));


    addObject(new DrawableObject(Models::Sphere,ShaderType::Phong,Textures::Red, Materials::Metal))
        ->getTransformations()
        ->addTransform(new Translate(glm::vec3(-2.f, 0.f,0.f)))
    ;
    addObject(new DrawableObject(Models::Sphere,ShaderType::Phong,Textures::Red, Materials::Metal))
        ->getTransformations()
        ->addTransform(new Translate(glm::vec3(2.f, 0.f,0.f)))
    ;
    addObject(new DrawableObject(Models::Sphere,ShaderType::Phong,Textures::Red, Materials::Metal))
        ->getTransformations()
        ->addTransform(new Translate(glm::vec3(0.f, 2.f,0.f)))
    ;
    addObject(new DrawableObject(Models::Sphere,ShaderType::Phong,Textures::Red, Materials::Metal))
        ->getTransformations()
        ->addTransform(new Translate(glm::vec3(0.f, -2.f,0.f)))
        ;


}