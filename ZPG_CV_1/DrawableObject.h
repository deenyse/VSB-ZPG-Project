#pragma once
#include "ShaderProgram.h"
#include "Model.h"

#include <GL/glew.h>
#include <stdio.h>

class DrawableObject
{
protected:
	ShaderProgram* shaderProgram = NULL;
	Model* model = NULL;
	int verticiesNum = 0;
public:
	DrawableObject(const float* points, int verticiesNum);

	void draw();
};

