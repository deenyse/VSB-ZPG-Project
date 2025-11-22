#include "PhongShaderProgram.h"

PhongShaderProgram::PhongShaderProgram() : MultiLightShaderProgram("ShaderSource/multiLight.vert","ShaderSource/phongMultiLight.frag") {

}

ShaderType PhongShaderProgram::getShaderType() {
    return ShaderType::Phong;
}