#pragma once
#include"TextureInstance.h"

class TextureLoader {
private:
    static std::unordered_map<std::string, TextureInstance*> textureCache;
public:
    static TextureInstance* loadTexture(std::string fileName);
    static TextureInstance* loadTexture(glm::vec3 color);
};