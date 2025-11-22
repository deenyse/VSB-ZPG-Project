#pragma once
#include "ShaderPair.h"

namespace ShaderSources {
    extern const ShaderPair Phong;
    extern const ShaderPair Bling;
    extern const ShaderPair Constant;

    const ShaderPair* Get(ShaderType type);

}