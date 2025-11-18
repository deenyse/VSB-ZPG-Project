#pragma once
#include <ctime>
#include <cstdlib>

#include "Translate.h"

#include "DynamicTransform.h"
class RandomTranslation : public Translate, public DynamicTransform
{
private:
    glm::vec3 velocity;   
    float range;          
    float halfCubeSize;   

    float randomFloat(float min, float max);
public:
    RandomTranslation(float range, float cubeSize);

    glm::mat4 getMatrix() override;
    void update(float deltaTime) override;
};