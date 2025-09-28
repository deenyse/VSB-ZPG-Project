#pragma once
#include "Model.h"


class Rectangle : public Model
{
private:
	// Coordinates			//Colors
    float points[36] = {
         0.9f,  0.9f,  0.0f, 1.0f, 1.0f, 0.0f,  // верхний правый
         0.9f,  0.0f,  0.5f, 1.0f, 1.0f, 0.0f,  // нижний правый
         0.0f,  0.0f,  0.0f, 1.0f, 1.0f, 0.0f,  // нижний левый
         0.9f,  0.9f,  0.0f, 1.0f, 1.0f, 0.0f,  // верхний правый
         0.0f,  1.0f,  0.0f, 1.0f, 1.0f, 0.0f,  // верхний левый
         0.0f,  0.0f,  0.0f, 1.0f, 1.0f, 0.0f   // нижний левый
    };

public:
	void create() override;
	void draw() override;

};

