#pragma once
#include <ctime>
#include <cstdlib>

#include "Translate.h"

class RandomTranslation : public Translate
{
private:
    glm::vec3 velocity;   
    float range;          
    float halfCubeSize;   

    float randomFloat(float min, float max);

public:
    RandomTranslation(float range, float cubeSize);

    glm::mat4 getMatrix() override;

};