#include "Textures.h"

namespace Textures {
    TextureDataBase* Red =  new ColorTexture(glm::vec3(1.0f, 0.0f, 0.0f));
    TextureDataBase* Yellow = new ColorTexture(glm::vec3(1.0f, 0.0f, 0.0f));

    TextureDataBase* Shrek = new FileTexture( "../Models/shrek.png");
    TextureDataBase* Fiona = new FileTexture( "../Models/fiona.png");
    TextureDataBase* Earth = new FileTexture( "../Models/earth_texture.jpg");
    TextureDataBase* Moon = new FileTexture( "../Models/moon_texture.jpg");
    TextureDataBase* Sun = new FileTexture( "../Models/sun_texture.jpg");
    TextureDataBase* Grass = new FileTexture( "../Models/grass.png");
    TextureDataBase* Skydome = new FileTexture( "../Models/skydome.png");
    TextureDataBase* Toiled = new FileTexture( "../Models/toiled.jpg");
}
