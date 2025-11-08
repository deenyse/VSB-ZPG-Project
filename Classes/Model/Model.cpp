#include "Model.h"

Model::Model(const float* points, int verticesNum){
    this->verticesNum = verticesNum;
    // Copy data into vector to ensure pointer stays valid
    vertices.assign(points, points + verticesNum * 6);

    setupBuffers();
}

Model::Model(const std::vector<float>& points) {
    vertices = points;
    verticesNum = vertices.size() / 6; // Assuming stride=6 (pos + normal)

    setupBuffers();
}

void Model::setupBuffers() {
    // Generate VAO and bind it
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate VBO and upload vertex data
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Vertex attributes: position (layout 0) and normal (layout 1)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Unbind VAO for safety
    glBindVertexArray(0);
}