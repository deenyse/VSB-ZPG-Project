#pragma once
#include "../Shader/Shader.h"
#include "../Shader/ShaderProgram.h"
#include "../Shader/StructShaderPair.h"

#include "../Model/Model.h"
#include "../Transformation/Transform.h"
#include "../Transformation/Translate.h"
#include "../Texture/Texture.h"
#include "../Material/StructMaterialData.h"
#include <GL/glew.h>
#include <stdio.h>
#include <vector>

#include "../Light/Light.h"

#include "../Observer/Subject.h"
#include "Light/LightManager.h"
#include "../Model/StructModelData.h"
#include "Material/StructMaterials.h"

class DrawableObject
{
protected:
	ShaderProgram* shaderProgram = nullptr;
	Model* model = nullptr;
	Transform* transformations;
	Texture* texture;
	const MaterialData* material;
	GLuint id;
public:
	DrawableObject(const ModelData modelData, Camera* camera, ShaderPair shaderSource, LightManager* lightManager, Texture* texture, const MaterialData* materials);
	virtual ~DrawableObject() = default;
	Transform* getTransformations();
	void moveObject(glm::vec3 offset);

	GLuint getID();
	void setId(GLuint id);

	void draw();
};

