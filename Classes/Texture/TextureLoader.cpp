#include "TextureLoader.h"

#include <string>
#include <glm/glm.hpp>

std::string colorToString(const glm::vec3& color) {
    return std::to_string(color.r) + "," + std::to_string(color.g) + "," + std::to_string(color.b);
}


std::unordered_map<std::string, TextureInstance*> TextureLoader::textureCache;

TextureInstance* TextureLoader::loadTexture(std::string fileName) {
    if (auto it = textureCache.find(fileName); it != textureCache.end()) {
        return it->second;
    }

    TextureInstance* texture = new TextureInstance(fileName);
    textureCache[fileName] = texture;
    return texture;
}
TextureInstance* TextureLoader::loadTexture(glm::vec3 color) {
    auto key = colorToString(color);
    if (auto it = textureCache.find(key); it != textureCache.end()) {
        return it->second;
    }

    TextureInstance* texture = new TextureInstance(color);
    textureCache[key] = texture;
    return texture;
}