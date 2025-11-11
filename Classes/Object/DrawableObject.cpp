#include "DrawableObject.h"
#include "../Model/ModelLoader.h"


DrawableObject::DrawableObject(const ModelData modelData, Camera* camera, ShaderPair shaderSource, LightManager* lighMmanager, Texture* texture){
	// Initialize shader program
	shaderProgram = new ShaderProgram(new Shader(GL_VERTEX_SHADER, shaderSource.vertex), new Shader(GL_FRAGMENT_SHADER, shaderSource.fragment), camera, lighMmanager);
	// Load object model
	model = ModelLoader::LoadModel(modelData); // create the model (VAO,VBO)
	transformations = new Transform();
	this->texture = texture;
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