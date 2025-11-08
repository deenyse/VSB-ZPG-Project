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
#include "Light/LightManager.h"
#include "../Model/StructModelData.h"
class DrawableObject : public Subject
{
protected:
	ShaderProgram* shaderProgram = nullptr;
	Model* model = nullptr;
	Transform* transformations;
public:
	DrawableObject(const ModelData modelData, Camera* camera, ShaderPair shaderSource, LightManager* lightManager);
	Transform* getTransformations();
	void draw();
};

