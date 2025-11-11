#pragma once
#include <GL/glew.h>
#include "../External/stb-image-header.h"
#include <iostream>
#include <string>
#include <glm/vec3.hpp> // glm::vec3

class Texture {
private:
    GLuint textureID;

public:
    Texture(std::string fileName);
    Texture(glm::vec3 color);
    void bind();
};