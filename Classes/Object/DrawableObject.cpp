#include "DrawableObject.h"
#include "../Model/ModelLoader.h"
#include "Transformation/Translate.h"


DrawableObject::DrawableObject(const ModelData modelData, Camera* camera, ShaderPair shaderSource, LightManager* lighMmanager, Texture* objTexture, MaterialData material) : texture(objTexture), material(material){
	// Initialize shader program
	shaderProgram = new ShaderProgram(shaderSource, camera, lighMmanager);
	// Load object model
	model = ModelLoader::LoadModel(modelData); // create the model (VAO,VBO)
	transformations = new Transform();
};


void DrawableObject::draw()
{
	transformations->updateDynamicTransforms(1);
	shaderProgram->useProgram(); // use the shader program of this object
	shaderProgram->setUniform("modelMatrix", transformations->getMatrix()); //set the model matrix uniform in the shader
	if (shaderProgram->shaderType != ShaderType::Constant) {
		shaderProgram->setUniform("material.ra", material.ra);
		shaderProgram->setUniform("material.rd", material.rd);
		shaderProgram->setUniform("material.rs", material.rs);
		shaderProgram->setUniform("material.h",  material.h);
	}
	texture->bind();
	model->bind(); //bind the VAO of the model

	glDrawArrays(GL_TRIANGLES, 0, model->getVerticesNum()); //mode,first,count

	glBindVertexArray(0);
	glUseProgram(0);

}

Transform* DrawableObject::getTransformations() {
	return transformations;
}

int Model::getVerticesNum() {
	return verticesNum;
}
GLuint DrawableObject::getID() {
	return id;
}

void DrawableObject::setId(GLuint id) {
	this->id = id;
}

void DrawableObject::moveObject(glm::vec3 offset) {
	glm::mat4 M = transformations->getMatrix();

	glm::quat q = glm::quat_cast(M);

	glm::mat3 R = glm::mat3_cast(q);

	glm::vec3 localOffset = glm::transpose(R) * offset;

	transformations->addTransform(new Translate(localOffset));
}