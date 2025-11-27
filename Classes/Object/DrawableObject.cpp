#include "DrawableObject.h"
#include "../Model/ModelLoader.h"
#include "Shader/MultiLightShaderProgram.h"
#include "Shader/ShaderFactory.h"
#include "Texture/TextureLoader.h"
#include "Transformation/Translate.h"

int DrawableObject::objectsCount = 0;

int DrawableObject::generateNewId() {
	return ++objectsCount;
}

DrawableObject::DrawableObject(const ModelDataBase* modelData, ShaderType type, TextureDataBase* textureData, const MaterialData* materials) : material(materials){
	shaderProgram = ShaderFactory::getShader(type);
	model = ModelLoader::LoadModel(modelData);
	texture = TextureLoader::loadTexture(textureData);
	transformations = new Transform();
	id = generateNewId();
};

void DrawableObject::updateState(float dt) {
	transformations->updateDynamicTransforms(dt);
}

void DrawableObject::draw()
{
	shaderProgram->setUniform("material",material);

	shaderProgram->setUniform("modelMatrix", transformations->getMatrix()); //set the model matrix uniform in the shader

	texture->bind();

	model->bind(); //bind the VAO of the model
	glDrawArrays(GL_TRIANGLES, 0, model->getVerticesNum()); //mode,first,count
	glBindVertexArray(0);
}

ShaderType DrawableObject::getShaderType() {
	return shaderProgram->getShaderType();
}

Transform* DrawableObject::getTransformations() {
	return transformations;
}

GLuint DrawableObject::getID() {
	return id;
}

void DrawableObject::moveObject(glm::vec3 offset) {
	glm::mat4 M = transformations->getMatrix();

	glm::quat q = glm::quat_cast(M);

	glm::mat3 R = glm::mat3_cast(q);

	glm::vec3 localOffset = glm::transpose(R) * offset;

	transformations->addTransform(new Translate(localOffset));
}