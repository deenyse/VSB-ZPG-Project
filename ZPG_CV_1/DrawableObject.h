#pragma once
#include "Shader.h"
#include "ShaderProgram.h"

#include "Model.h"
#include "Transform.h"
#include "TransformBase.h"

#include <GL/glew.h>
#include <stdio.h>
#include <vector>
#include "StructShaderSources.h"

#include "Light.h"
class DrawableObject
{
protected:
	ShaderProgram* shaderProgram = NULL;
	Model* model = NULL;
	Transform* transformations;
	int verticiesNum = 0;
public:
	DrawableObject(const float* points, int verticiesNum, Camera* camera, ShaderPair shaderSource, std::vector<Light*> lights);
	Transform* getTransformations();
	void draw();
};

