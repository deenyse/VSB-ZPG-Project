#include "Skydome.h"


Skydome::Skydome(const ModelData modelData, Texture *texture, Camera* camera)
    :DrawableObject(modelData, ShaderType::Constant, texture){

    this->camera = camera;
    camera->attach(this);
}

void Skydome::draw(float dt) {
    glDepthMask(GL_FALSE);
    glDisable(GL_STENCIL_TEST);
    DrawableObject::draw(dt);
    glDepthMask(GL_TRUE);
    glEnable(GL_STENCIL_TEST);
}

void Skydome::update(ObservableSubjects subject) {
    if (subject != ObservableSubjects::SCamera)
        return;

    transformations->clearTransformations();

    transformations->addTransform(new Translate(camera->getPosition()));
    transformations->addTransform(new Translate(glm::vec3(0,-0.5f,0)));
}

