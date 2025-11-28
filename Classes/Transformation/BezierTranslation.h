#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "Translate.h"
#include "DynamicTransform.h"

class BezierTranslation : public Translate, public DynamicTransform {
private:

    float speed;
    float t = 0.0f;

    glm::vec3 offset;

    std::vector<glm::vec3> controlPoints;
    glm::vec3 currentDirection;
    glm::vec3 bezierPoint(float t);
    glm::vec3 bezierTangent(float t);
    size_t currentSegmentStart = 0;
public:
    BezierTranslation(float speed, glm::vec3 translate);

    void addPoint(const glm::vec3& p);

    void update(float deltaTime) override;
    glm::mat4 getMatrix() override;
};
