#pragma once
#include "ShaderProgram.h"


class ConstantShaderProgram : public ShaderProgram {

public:
    ConstantShaderProgram();
    void update(ObservableSubjects subject) override;
    ShaderType getShaderType() override;
    using ShaderProgram::setUniform;
    void setUniform(const GLchar* name, const MaterialData* value) override;
};
