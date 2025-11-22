#pragma once
#include "DrawableObject.h"
#include "../Shader/ShaderSources.h"
#include "../Observer/Observer.h"
#include "../Observer/EnumObservableSubjects.h"
#include "../Transformation/Scale.h"
#include "../Transformation/Translate.h"
#include "../Transformation/Rotate.h"
class Skydome : public DrawableObject, public Observer {
    // DrawableObject(const ModelData modelData, Camera* camera, ShaderPair shaderSource, LightManager* lightManager, Texture* texture);
public:
    Skydome(const ModelData modelData, Texture* texture, Camera* camera);
    void draw(float dt) override;

private:
    void update(ObservableSubjects subject) override;
    Camera* camera;
};