#pragma once


class DynamicTransform {
public:
    virtual void update(float deltaTime) = 0;
};