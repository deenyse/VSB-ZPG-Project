#pragma once
#include "TextureInstance.h"
#include "TextureLoader.h"
#include "TextureData.h"


namespace Textures {
    extern TextureDataBase* Red;
    extern TextureDataBase* Yellow;
    extern TextureDataBase* Green;
    extern TextureDataBase* White;

    extern TextureDataBase* Shrek;
    extern TextureDataBase* Fiona;
    extern TextureDataBase* Earth;
    extern TextureDataBase* Moon;
    extern TextureDataBase* Sun;
    extern TextureDataBase* Grass;
    extern TextureDataBase* Skydome;
    extern TextureDataBase* Toiled;

    static TextureDataBase* AddCustom(std::string name);
}