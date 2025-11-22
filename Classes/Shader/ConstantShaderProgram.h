#pragma once
#include "ShaderProgram.h"


class ConstantShaderProgram : public ShaderProgram {

public:
    ConstantShaderProgram();
    void update(ObservableSubjects subject) override;
    ShaderType getShaderType() override;
};
