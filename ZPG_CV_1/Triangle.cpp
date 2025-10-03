#include "Triangle.h"

void Triangle::create(){

	//Vertex Array Object (VAO) // instructions how to handle the vertex buffer
	glGenVertexArrays(1, &VAO); //generate 1 new VAO
	glBindVertexArray(VAO); //bind the VAO


	//vertex buffer object (VBO) //coordinates of vertices
	glGenBuffers(1, &VBO); // generate 1 new VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	
	/*glBindBuffer(GL_ARRAY_BUFFER, VBO);*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);	
	glEnableVertexAttribArray(0); //enable vertex attributes // 0-> layout(location=0) in vec3 vp;
	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1); //enable vertex attributes 1

	shaderProgram->createProgram();
}


void Triangle::draw(){
	shaderProgram->useProgram();
	// bind the VAO (the triangle)
	glBindVertexArray(VAO);
	// draw triangles
	glDrawArrays(GL_TRIANGLES, 0, 3); //mode,first,count
}