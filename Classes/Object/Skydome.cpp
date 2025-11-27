#include "Skydome.h"


Skydome::Skydome(Model* model, TextureInstance *texture, Camera* camera)
    :DrawableObject(model, ShaderFactory::getShader(ShaderType::Constant), texture){

    this->camera = camera;
    camera->attach(this);
}

void Skydome::setAmbientIntensity(float intensity) {
    ambientLightIntensity = intensity;
}

void Skydome::draw() {
    shaderProgram->setUniform("ambient", ambientLightIntensity);
    DrawableObject::draw();

}

void Skydome::update(ObservableSubjects subject) {
    if (subject != ObservableSubjects::SCamera)
        return;

    transformations->clearTransformations();

    transformations->addTransform(new Translate(camera->getPosition()));
    transformations->addTransform(new Translate(glm::vec3(0,-0.5f,0)));
}

