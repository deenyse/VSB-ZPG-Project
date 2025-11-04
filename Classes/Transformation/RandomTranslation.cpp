#include "RandomTranslation.h"

float RandomTranslation::randomFloat(float min, float max) {
    return min + (max - min) * (float)rand() / (float)RAND_MAX;
}



RandomTranslation::RandomTranslation(float range, float cubeSize)
    : Translate(glm::vec3(0.0f)), range(range), halfCubeSize(cubeSize / 2.0f)
{
    srand(static_cast<unsigned>(time(nullptr)));

    velocity = glm::vec3(
        randomFloat(-range, range),
        randomFloat(-range, range),
        randomFloat(-range, range)
    );
}

glm::mat4 RandomTranslation::getMatrix()
{
    velocity += glm::vec3(
        randomFloat(-range * 0.05f, range * 0.05f),
        randomFloat(-range * 0.05f, range * 0.05f),
        randomFloat(-range * 0.05f, range * 0.05f)
    );

    offset += velocity;

    if (offset.x > halfCubeSize || offset.x < -halfCubeSize) velocity.x = -velocity.x;
    if (offset.y > halfCubeSize || offset.y < -halfCubeSize) velocity.y = -velocity.y;
    if (offset.z > halfCubeSize || offset.z < -halfCubeSize) velocity.z = -velocity.z;

    float maxSpeed = range;
    if (glm::length(velocity) > maxSpeed)
        velocity = glm::normalize(velocity) * maxSpeed;

    return glm::translate(glm::mat4(1.0f), offset);
}