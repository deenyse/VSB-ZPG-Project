#include "BezierTranslation.h"

BezierTranslation::BezierTranslation(float speed, glm::vec3 translate)
    : Translate(glm::vec3(0.0f)), speed(speed)
{
    addPoint(translate);
    offset = translate;
    currentDirection = glm::vec3(0.0f, 0.0f, 1.0f);
}

glm::vec3 BezierTranslation::bezierTangent(float t) {
    const glm::vec3& P0 = controlPoints[currentSegmentStart];
    const glm::vec3& P1 = controlPoints[currentSegmentStart + 1];
    const glm::vec3& P2 = controlPoints[currentSegmentStart + 2];
    const glm::vec3& P3 = controlPoints[currentSegmentStart + 3];

    float u = 1.0f - t;
    float u2 = u * u;
    float t2 = t * t;

    glm::vec3 tangent = 3.0f * u2 * (P1 - P0) +
                        6.0f * u * t * (P2 - P1) +
                        3.0f * t2 * (P3 - P2);

    if (glm::length(tangent) > 0.0001f) {
        return glm::normalize(tangent);
    }

    return glm::vec3(1.0f, 0.0f, 0.0f);
}

glm::vec3 BezierTranslation::bezierPoint(float t) {
    const glm::vec3& P0 = controlPoints[currentSegmentStart];
    const glm::vec3& P1 = controlPoints[currentSegmentStart + 1];
    const glm::vec3& P2 = controlPoints[currentSegmentStart + 2];
    const glm::vec3& P3 = controlPoints[currentSegmentStart + 3];

    float u = 1.0f - t;
    float u2 = u * u;
    float u3 = u2 * u;
    float t2 = t * t;
    float t3 = t2 * t;

    return u3 * P0 + 3.0f * u2 * t * P1 + 3.0f * u * t2 * P2 + t3 * P3;
}

void BezierTranslation::addPoint(const glm::vec3& p) {
    controlPoints.push_back(p);
}

void BezierTranslation::update(float deltaTime) {
    if (controlPoints.size() < 4) return;

    t += speed * deltaTime;

    while (t >= 1.0f && (currentSegmentStart + 3 + 3) < controlPoints.size()) {
        t -= 1.0f;
        currentSegmentStart += 3;
    }

    if (t >= 1.0f) {
        t = 1.0f;
    }

    offset = bezierPoint(t);
    currentDirection = bezierTangent(t);
}

glm::mat4 BezierTranslation::getMatrix() {
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, offset);

    glm::mat4 rotation = glm::inverse(glm::lookAt(glm::vec3(0.0f), glm::vec3(0.0f) + currentDirection, glm::vec3(0.0f, 1.0f, 0.0f)));

    model = model * rotation;


    return model;
}