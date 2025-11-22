#include "Skydome.h"


Skydome::Skydome(const ModelData modelData, Texture *texture, Camera* camera)
    :DrawableObject(modelData, ShaderType::Phong, texture, Materials::Skydome){

    this->camera = camera;
    camera->attach(this);
}


void Skydome::update(ObservableSubjects subject) {
    if (subject != ObservableSubjects::SCamera)
        return;

    transformations->clearTransformations();

    transformations->addTransform(new Translate(camera->getPosition()));
    transformations->addTransform(new Translate(glm::vec3(0,-0.5f,0)));


}
