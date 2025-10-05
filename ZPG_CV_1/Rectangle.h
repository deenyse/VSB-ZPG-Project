#pragma once
#include "Model.h"


class Rectangle : public Model
{
private:
	// Coordinates			//Colors
    float points[36] = {
         0.9f,  0.9f,  0.0f, 1.0f, 1.0f, 0.0f,  // top r
         0.9f,  0.1f,  0.5f, 1.0f, 1.0f, 0.0f,  // btm r
         0.0f,  0.1f,  0.1f, 1.0f, 1.0f, 0.0f,  // btm l
         0.9f,  0.9f,  0.0f, 1.0f, 1.0f, 0.0f,  // top r
         0.0f,  0.9f,  0.0f, 1.0f, 1.0f, 0.0f,  // top l
         0.0f,  0.1f,  0.1f, 1.0f, 1.0f, 0.0f   // btm l
    };

public:
	void create() override;
	void draw() override;

};

