#include "RandomTranslation.h"

float RandomTranslation::randomFloat(float min, float max) {
    return min + (max - min) * (float)rand() / (float)RAND_MAX;
}

glm::vec3 RandomTranslation::randomPointInCube() {
    return glm::vec3(
        randomFloat(-halfCubeSize, halfCubeSize),
        randomFloat(-halfCubeSize, halfCubeSize),
        randomFloat(-halfCubeSize, halfCubeSize)
    );
}

RandomTranslation::RandomTranslation(float cubeSize, float speed)
    : Translate(glm::vec3(0.0f)), halfCubeSize(cubeSize / 2.0f), speed(speed)
{
    // create 2 key points
    controlPoints.push_back(randomPointInCube());
    controlPoints.push_back(randomPointInCube());
}



void RandomTranslation::update(float deltaTime) {
    t += speed * deltaTime;

    if (t >= 1.0f) {
        t = 0.0f;
        controlPoints[0] = controlPoints[1];
        controlPoints[1] = randomPointInCube();
    }

    glm::vec3 A = controlPoints[0];
    glm::vec3 B = controlPoints[1];

    offset = (1.0f - t) * A + t * B;
}



glm::mat4 RandomTranslation::getMatrix() {
    return glm::translate(glm::mat4(1.0f), offset);
}
