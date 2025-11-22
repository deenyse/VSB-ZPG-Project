#pragma once
#include "ShaderPair.h"

namespace ShaderSources {
    extern const ShaderPair Phong;
    extern const ShaderPair Bling;

    const ShaderPair* Get(ShaderType type);

}