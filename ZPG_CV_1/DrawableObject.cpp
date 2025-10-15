#include "DrawableObject.h"
#include "ShaderSources.h"


DrawableObject::DrawableObject(const float* points, int verticiesNum, Camera* camera) : verticiesNum(verticiesNum){
	//shaderProgram = new ShaderProgram(new Shader(GL_VERTEX_SHADER, vertexCameraShaderSource), new Shader(GL_FRAGMENT_SHADER ,fragmentShaderSource), camera);  // create the shader program (vertex and fragment shaders) || SAFE
	shaderProgram = new ShaderProgram(new Shader(GL_VERTEX_SHADER, std::string("ShaderSource/constant.vert")), new Shader(GL_FRAGMENT_SHADER, std::string("ShaderSource/constant.frag")), camera);
	model = new Model(points, verticiesNum); // create the model (VAO,VBO)
	transformations = new Transform();

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