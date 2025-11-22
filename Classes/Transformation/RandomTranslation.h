#pragma once
#include <ctime>
#include <cstdlib>

#include "Translate.h"

#include "DynamicTransform.h"
class RandomTranslation : public Translate , public DynamicTransform{
private:
    float halfCubeSize;

    std::vector<glm::vec3> controlPoints;
    int currentIndex = 0;
    float t = 0.0f;
    float speed;

    glm::vec3 offset;

    glm::vec3 randomPointInCube();
    float randomFloat(float min, float max);

public:
    RandomTranslation(float cubeSize, float speed = 0.2f);

    void update(float deltaTime) override;
    glm::mat4 getMatrix() override;
};
