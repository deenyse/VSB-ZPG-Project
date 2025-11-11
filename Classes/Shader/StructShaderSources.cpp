#include "StructShaderSources.h"
#include "EnumShaderType.h"
const ShaderPair ShaderSources::Constant = { ShaderType::Constant, "ShaderSource/constant.vert", "ShaderSource/constant.frag" };
const ShaderPair ShaderSources::Phong = { ShaderType::Multilight, "ShaderSource/phongMultiLight.vert",    "ShaderSource/phongMultiLight.frag" };
const ShaderPair ShaderSources::Bling = { ShaderType::Multilight, "ShaderSource/bling.vert",    "ShaderSource/bling.frag" };
