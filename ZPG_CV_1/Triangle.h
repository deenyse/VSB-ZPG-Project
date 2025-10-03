#pragma once
#include "DrawableObject.h"
#include "ShaderProgram.h"

#include <stdio.h>

const float points[18] = {
-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // brm l
 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // btm r
 0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f  // top
};


class Triangle : public DrawableObject
{
private:
	//const float points[18] = {
	//-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // brm l
	// 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // btm r
	// 0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f  // top
	//};
	//
public:
	Triangle() :DrawableObject(points, 3) {
	};
};

