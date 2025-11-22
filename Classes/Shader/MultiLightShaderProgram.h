#pragma once
#include "ShaderProgram.h"
#include "Light/LightManager.h"

#include "../Observer/EnumObservableSubjects.h"

class MultiLightShaderProgram : public ShaderProgram{

protected:
    LightManager* lightManager = nullptr;
public:
    MultiLightShaderProgram(const char* vertex, const char* fragment);
    void attachLightManager(LightManager* lm) override;
    void update(ObservableSubjects subject) override;
};
