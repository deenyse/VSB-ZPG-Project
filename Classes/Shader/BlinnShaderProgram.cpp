#include "BlinnShaderProgram.h"


BlinnShaderProgram::BlinnShaderProgram() : MultiLightShaderProgram("ShaderSource/multiLight.vert","ShaderSource/blinnMultiLight.frag") {

}

ShaderType BlinnShaderProgram::getShaderType() {
    return ShaderType::Blinn;
}