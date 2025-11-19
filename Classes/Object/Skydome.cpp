#include "Skydome.h"


Skydome::Skydome(const ModelData modelData, Camera *camera, Texture *texture, LightManager *lightManager)
    :DrawableObject(modelData, camera, ShaderSources::Phong, lightManager, texture, Materials::Skydome){

    this->camera = camera;
    if (camera)
        camera->attach(this);

}


void Skydome::update(ObservableSubjects subject) {
    if (subject != ObservableSubjects::SCamera)
        return;

    transformations->clearTransformations();

    transformations->addTransform(new Translate(camera->getPosition()));
    transformations->addTransform(new Translate(glm::vec3(0,-0.5f,0)));


}
