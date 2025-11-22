#include "DrawableObject.h"
#include "../Model/ModelLoader.h"
#include "Shader/MultiLightShaderProgram.h"
#include "Shader/ShaderFactory.h"
#include "Transformation/Translate.h"

int DrawableObject::objectsCount = 0;

int DrawableObject::generateNewId() {
	return ++objectsCount;
}


DrawableObject::DrawableObject(const ModelData modelData, ShaderType shaderType, Texture* texture, const MaterialData* materials) : texture(texture), material(materials){
	// Initialize shader program
	shaderProgram = ShaderFactory::getShader(shaderType);
	// Load object model
	model = ModelLoader::LoadModel(modelData); // create the model (VAO,VBO)
	transformations = new Transform();
	id = this->generateNewId();
};

void DrawableObject::updateState(float dt) {
	transformations->updateDynamicTransforms(dt);
}

void DrawableObject::draw()
{

	if (auto mlsp = dynamic_cast<MultiLightShaderProgram*>(shaderProgram)) {
		if (material)
			mlsp->setUniform("material",material);
		else
			mlsp->setUniform("material",Materials::Metal);
	}
	else {
		// shaderProgram->setUniform("w",0.5f);
	}

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