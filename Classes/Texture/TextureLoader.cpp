#include "TextureLoader.h"

#include <string>
#include <glm/glm.hpp>

std::string colorToString(const glm::vec3& color) {
    return std::to_string(color.r) + "," + std::to_string(color.g) + "," + std::to_string(color.b);
}


std::unordered_map<int, TextureInstance*> TextureLoader::textureCache;

TextureInstance* TextureLoader::loadTexture(TextureDataBase* textureData) {

    if (auto it = textureCache.find(textureData->id); it != textureCache.end()) {
        return it->second;
    }
    TextureInstance* texture;

    if (auto ft = dynamic_cast<FileTexture*>(textureData)) {
        texture = new TextureInstance(ft->texturePath);
    }
    else {
        auto ct = dynamic_cast<ColorTexture*>(textureData);
        texture = new TextureInstance(ct->color);
    }

    textureCache[textureData->id] = texture;
    return texture;
}
