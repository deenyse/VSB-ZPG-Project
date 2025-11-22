#include "ShaderSources.h"
#include "EnumShaderType.h"

#include "ShaderSources.h"

namespace ShaderSources {

    const ShaderPair Phong = {
        ShaderType::Phong,
        "ShaderSource/phongMultiLight.vert",
        "ShaderSource/phongMultiLight.frag"
    };

    const ShaderPair Bling = {
        ShaderType::Bling,
        "ShaderSource/bling.vert",
        "ShaderSource/bling.frag"
    };
    const ShaderPair Constant = {
        ShaderType::Constant,
        "ShaderSource/constant.vert",
        "ShaderSource/constant.frag"
    };

    const ShaderPair* Get(ShaderType type)
    {
        switch (type)
        {
            case ShaderType::Phong:
                return &Phong;

            case ShaderType::Bling:
                return &Bling;

            case ShaderType::Constant:
                return &Constant;

            default:
                return nullptr;
        }
    }
}
