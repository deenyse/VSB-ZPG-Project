#pragma once
#include <GL/glew.h>
#include "../External/stb-image-header.h"
#include <iostream>
#include <string>
#include <glm/vec3.hpp> // glm::vec3

class TextureInstance {
private:
    GLuint textureID;
public:
    TextureInstance(std::string fileName);
    TextureInstance(glm::vec3 color);
    void bind();
};