#include "Model.h"
#include "../External/stb-image-header.h"
#include <iostream>
Model::Model(const float* points, int verticesNum){
    this->verticesNum = verticesNum;
    // Copy data into vector to ensure pointer stays valid
    vertices.assign(points, points + verticesNum * 8);

    setupBuffers();
}

Model::Model(const std::vector<float>& points) {
    vertices = points;
    verticesNum = vertices.size() / 8; // Assuming stride=6 (pos + normal)

    setupBuffers();
}
void Model::loadTexture(const std::string& path) {
    stbi_set_flip_vertically_on_load(true);

    int width, height, channels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 4);
    if (!data) {
        std::cerr << "Error loading texture: " << path << std::endl;
        return;
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
}
void Model::setupBuffers() {
    // Generate VAO and bind it
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate VBO and upload vertex data
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);


    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);


    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    // Vertex attributes: position (layout 0) and normal (layout 1)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(6 * sizeof(float)));

    // Unbind VAO for safety
    glBindVertexArray(0);
}