#pragma once
#include <string>
#include <glm/vec3.hpp>

struct TextureDataBase {
    static int texturesCount;
    static int generateNewId();
    const int id;
    TextureDataBase() : id(generateNewId()) {}
    virtual ~TextureDataBase() = default;
};

struct FileTexture : public TextureDataBase {
    const std::string texturePath;
    FileTexture(const std::string& texturePath) : texturePath(texturePath) {}
};

struct ColorTexture : public TextureDataBase {
    glm::vec3 color;
    ColorTexture(const glm::vec3& color) : color(color) {}
};