#pragma once
#include "DrawableObject.h"
#include "../Observer/Observer.h"
#include "../Observer/EnumObservableSubjects.h"
#include "../Shader/ShaderFactory.h"

#include "../Transformation/Scale.h"
#include "../Transformation/Translate.h"
#include "../Transformation/Rotate.h"
class Skydome : public DrawableObject, public Observer {
    // DrawableObject(const ModelData modelData, Camera* camera, ShaderPair shaderSource, LightManager* lightManager, Texture* texture);
public:
    Skydome(Model* model, TextureInstance *texture, Camera* camera);
    void draw() override;
    void setAmbientIntensity(float intensity);
private:
    void update(ObservableSubjects subject) override;
    Camera* camera;
    float ambientLightIntensity = 1.0f;
};