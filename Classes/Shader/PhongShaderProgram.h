#pragma once
#include "ConstantShaderProgram.h"
#include "MultiLightShaderProgram.h"
#include "ShaderProgram.h"


class PhongShaderProgram : public MultiLightShaderProgram{
public:
    PhongShaderProgram();
    ShaderType getShaderType() override;
};
