#include "ShaderFactory.h"

#include "ShaderSources.h"


std::unordered_map<ShaderType, ShaderProgram*> ShaderFactory::shaderCache;

ShaderProgram *ShaderFactory::getShader(ShaderType type) {
    if (auto it = shaderCache.find(type); it != shaderCache.end()) {
        return it->second;
    }

    ShaderProgram* loadedShader = new ShaderProgram(ShaderSources::Get(type));
    shaderCache[type] = loadedShader;

    return loadedShader;
}
