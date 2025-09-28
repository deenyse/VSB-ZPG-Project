#pragma once
#include "Model.h"


class Triangle : public Model
{
private:
	// Coordinates		//Colors
	float points[36] = {
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	   -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	   -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f
	};
public:
	void create() override;
	void draw() override;
	
};

