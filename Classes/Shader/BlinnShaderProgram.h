#pragma once
#include "MultiLightShaderProgram.h"


class BlinnShaderProgram : public MultiLightShaderProgram {
    public:
    BlinnShaderProgram();
    ShaderType getShaderType() override;

};
