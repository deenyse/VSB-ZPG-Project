#pragma once
#include "../Shader/Shader.h"
#include "../Shader/ShaderProgram.h"

#include "../Model/ModelInstance.h"
#include "../Transformation/Transform.h"
#include "../Transformation/Translate.h"
#include "../Texture/TextureInstance.h"
#include "../Material/StructMaterialData.h"
#include <GL/glew.h>
#include <stdio.h>
#include <vector>

#include "../Light/Light.h"

#include "../Observer/Subject.h"
#include "Light/LightManager.h"
#include "../Model/ModelData.h"
#include "Material/StructMaterials.h"
#include "../Texture/TextureData.h"
class DrawableObject
{
protected:
	static int objectsCount;
	static int generateNewId();
	ShaderProgram* shaderProgram = nullptr;
	ModelInstance* model = nullptr;
	Transform* transformations = nullptr;
	TextureInstance* texture = nullptr;
	const MaterialData* material = nullptr;
	GLuint id = 0;
public:
	DrawableObject(const ModelDataBase* model, ShaderType type, TextureDataBase* texture, const MaterialData* materials = nullptr);

	virtual ~DrawableObject() = default;

	ShaderType getShaderType();

	Transform* getTransformations();
	void moveObject(glm::vec3 offset);

	GLuint getID();

	void updateState(float dt);

	virtual void draw() ;
};

