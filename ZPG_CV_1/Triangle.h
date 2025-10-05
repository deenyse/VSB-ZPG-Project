#pragma once
#include "DrawableObject.h"
#include "ShaderProgram.h"

#include <stdio.h>

//Need to define points globaly to ensure they are in memory when the constructor of Model is called
const float points[18] = {
-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // brm l
 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // btm r
 0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f  // top
};


class Triangle : public DrawableObject
{
public:
	Triangle() :DrawableObject(points, 3) {
	};
};

