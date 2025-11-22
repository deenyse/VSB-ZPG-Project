#include "ShaderFactory.h"

#include "BlinnShaderProgram.h"
#include "ConstantShaderProgram.h"
#include "PhongShaderProgram.h"


std::unordered_map<ShaderType, ShaderProgram*> ShaderFactory::shaderCache;

ShaderProgram *ShaderFactory::getShader(ShaderType type) {
    if (auto it = shaderCache.find(type); it != shaderCache.end()) {
        return it->second;
    }

    ShaderProgram* loadedShader = nullptr;
    switch (type) {
        case ShaderType::Phong:
            loadedShader = new PhongShaderProgram();
            break;
        case ShaderType::Blinn:
            loadedShader = new BlinnShaderProgram();
            break;
        case ShaderType::Constant:
            loadedShader = new ConstantShaderProgram();
            break;
    }

    shaderCache[type] = loadedShader;

    return loadedShader;
}