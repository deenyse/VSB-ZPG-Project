#pragma once
#include "ShaderProgram.h"
#include "Model.h"
#include "Transform.h"
#include "TransformBase.h"

#include <GL/glew.h>
#include <stdio.h>

class DrawableObject
{
protected:
	ShaderProgram* shaderProgram = NULL;
	Model* model = NULL;
	Transform* transformations;
	int verticiesNum = 0;
public:
	DrawableObject(const float* points, int verticiesNum);
	Transform* getTransformations();
	void draw();
};

