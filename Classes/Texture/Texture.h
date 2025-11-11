#pragma once
#include <GL/glew.h>
#include "../External/stb-image-header.h"
#include <iostream>
#include <string>
class Texture {
private:
    GLuint textureID;

public:
    Texture(std::string fileName);
    void bind();
};