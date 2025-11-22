#pragma once
#include "ShaderProgram.h"


class ShaderFactory {
private:
    static std::unordered_map<ShaderType, ShaderProgram*> shaderCache;


public:
    static ShaderProgram* getShader(ShaderType type);
};
