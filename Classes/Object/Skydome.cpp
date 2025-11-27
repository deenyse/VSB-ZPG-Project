#include "Skydome.h"


Skydome::Skydome(const ModelDataBase* model, TextureDataBase *texture, const MaterialData* material, Camera* camera)
    :DrawableObject(model, ShaderType::Constant, texture, material){

    this->camera = camera;
    camera->attach(this);
}

void Skydome::setAmbientIntensity(float intensity) {
    ambientLightIntensity = intensity;
}

void Skydome::update(ObservableSubjects subject) {
    if (subject != ObservableSubjects::SCamera)
        return;

    transformations->clearTransformations();

    transformations->addTransform(new Translate(camera->getPosition()));
    transformations->addTransform(new Translate(glm::vec3(0,-0.5f,0)));
}

