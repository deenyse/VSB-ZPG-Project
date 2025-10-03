#include "DrawableObject.h"


DrawableObject::DrawableObject(const float* points, int verticiesNum) {
	this->verticiesNum = verticiesNum;
	shaderProgram = new ShaderProgram();  // create the shader program (vertex and fragment shaders)
	model = new Model(points, verticiesNum); // create the model (VAO,VBO)


};

void DrawableObject::draw()
{
	shaderProgram->useProgram(); // use the shader program of this object
	model->bind(); //bind the VAO of the model

	glDrawArrays(GL_TRIANGLES, 0, verticiesNum); //mode,first,count
}