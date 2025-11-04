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
#include "Light/LightManager.h"

class DrawableObject : public Subject
{
protected:
	ShaderProgram* shaderProgram = nullptr;
	Model* model = nullptr;
	Transform* transformations;
	int verticesNum = 0;
public:
	DrawableObject(const float* points, int verticiesNum, Camera* camera, ShaderPair shaderSource, LightManager* lightManager);
	DrawableObject(const std::string& objPath, Camera* camera, ShaderPair shaderSource, LightManager* lightManager);
	Transform* getTransformations();
	void draw();
};

