#pragma once
#include "../Shader/Shader.h"
#include "../Shader/ShaderProgram.h"
#include "../Shader/StructShaderPair.h"

#include "../Model/Model.h"
#include "../Transformation/Transform.h"
#include "../Transformation/TransformBase.h"

#include <GL/glew.h>
#include <stdio.h>
#include <vector>

#include "../Light/Light.h"

#include "../Observer/Subject.h"
#include "tiny_obj_loader.h"

class DrawableObject : public Subject
{
protected:
	ShaderProgram* shaderProgram = NULL;
	Model* model = NULL;
	Transform* transformations;
	int verticiesNum = 0;
public:
	DrawableObject(const float* points, int verticiesNum, Camera* camera, ShaderPair shaderSource, std::vector<Light*> lights);
	DrawableObject(const std::string& objPath, Camera* camera, ShaderPair shaderSource, std::vector<Light*> lights);
	Transform* getTransformations();
	void draw();
};

