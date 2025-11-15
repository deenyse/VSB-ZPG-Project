#pragma once
#include "../Shader/Shader.h"
#include "../Shader/ShaderProgram.h"
#include "../Shader/StructShaderPair.h"

#include "../Model/Model.h"
#include "../Transformation/Transform.h"
#include "../Texture/Texture.h"

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
	Texture* texture;
	GLint id;
public:
	DrawableObject(const ModelData modelData, Camera* camera, ShaderPair shaderSource, LightManager* lightManager, Texture* texture);
	Transform* getTransformations();
	GLint getID();
	void setId(GLuint id);
	void draw();
};

