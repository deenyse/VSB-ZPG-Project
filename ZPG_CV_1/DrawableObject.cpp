#include "DrawableObject.h"


DrawableObject::DrawableObject(const float* points, int verticiesNum) : verticiesNum(verticiesNum){
	shaderProgram = new ShaderProgram();  // create the shader program (vertex and fragment shaders)
	model = new Model(points, verticiesNum); // create the model (VAO,VBO)
	transformations = new Transform();

};

void DrawableObject::draw()
{
	shaderProgram->useProgram(); // use the shader program of this object
	shaderProgram->setUniform("modelMatrix", transformations->getTransformMatrix()); //set the model matrix uniform in the shader
	model->bind(); //bind the VAO of the model

	glDrawArrays(GL_TRIANGLES, 0, verticiesNum); //mode,first,count
}
DrawableObject* DrawableObject::addTransformation(IBasicTransform* t) { //addTransformation
	transformations->addTransform(t);

	return this;
}

