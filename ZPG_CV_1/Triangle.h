#pragma once
#include "Model.h"


class Triangle : public Model
{
private:
	// Coordinates		//Colors
	float points[18] = {
	-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // brm l
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // btm r
	 0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f  // top
	};

public:
	void create() override;
	void draw() override;
	
};

