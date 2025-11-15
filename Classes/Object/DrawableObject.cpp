#include "DrawableObject.h"
#include "../Model/ModelLoader.h"
#include "Transformation/Translate.h"


DrawableObject::DrawableObject(const ModelData modelData, Camera* camera, ShaderPair shaderSource, LightManager* lighMmanager, Texture* objTexture) : texture(objTexture){
	// Initialize shader program
	shaderProgram = new ShaderProgram(shaderSource, camera, lighMmanager);
	// Load object model
	model = ModelLoader::LoadModel(modelData); // create the model (VAO,VBO)
	transformations = new Transform();
	auto t = new Translate(glm::vec3(0));
	position = t->getPosition();
	transformations->addTransform(t);
};


void DrawableObject::draw()
{
	notify(ObservableSubjects::SObject);
	shaderProgram->useProgram(); // use the shader program of this object
	shaderProgram->setUniform("modelMatrix", transformations->getMatrix()); //set the model matrix uniform in the shader
	texture->bind();
	model->bind(); //bind the VAO of the model

	glDrawArrays(GL_TRIANGLES, 0, model->getVerticesNum()); //mode,first,count

	glBindVertexArray(0);
	glUseProgram(0);

}

int Model::getVerticesNum() {
	return verticesNum;
}
Transform* DrawableObject::getTransformations() {
	return transformations;
}

GLuint DrawableObject::getID() {
	return id;
}

void DrawableObject::setId(GLuint id) {
	this->id = id;
}

void DrawableObject::moveObject(glm::vec3 offset) {
	*position += offset;
}