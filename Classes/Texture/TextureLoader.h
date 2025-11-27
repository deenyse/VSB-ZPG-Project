#pragma once
#include"TextureInstance.h"
#include"TextureData.h"
class TextureLoader {
private:
    static std::unordered_map<int, TextureInstance*> textureCache;
public:
    static TextureInstance* loadTexture(TextureDataBase* textureData);
};