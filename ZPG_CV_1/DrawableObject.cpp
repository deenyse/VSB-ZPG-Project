#include "DrawableObject.h"



DrawableObject::DrawableObject(const float* points, int verticiesNum, Camera* camera) : verticiesNum(verticiesNum){
	shaderProgram = new ShaderProgram(new Shader(GL_VERTEX_SHADER, std::string(ShaderSources::VertexLamb)), new Shader(GL_FRAGMENT_SHADER, std::string(ShaderSources::FragmentLamb)), camera);
	model = new Model(points, verticiesNum); // create the model (VAO,VBO)
	transformations = new Transform();
	//this->light = new Light(glm::vec3(0.0f, 0.0f, 0.0f));
};

void DrawableObject::draw()
{
	shaderProgram->useProgram(); // use the shader program of this object
	shaderProgram->setUniform("modelMatrix", transformations->getMatrix()); //set the model matrix uniform in the shader

	model->bind(); //bind the VAO of the model

	glDrawArrays(GL_TRIANGLES, 0, verticiesNum); //mode,first,count

	glBindVertexArray(0);
}

Transform* DrawableObject::getTransformations() {
	return transformations;
}