#pragma once
#include "EnumShaderType.h"
struct ShaderPair {
    const ShaderType type;
    const char* vertex;
    const char* fragment;
};