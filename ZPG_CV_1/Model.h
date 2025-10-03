#pragma once
//Include GLEW
#include <GL/glew.h>

#include <stdio.h>
class Model
{
protected:
	GLuint VBO, VAO;
	int verticiesNum = 0;
public:
	Model(const float* points, int verticiesNum);

	void bind() {
		glBindVertexArray(VAO);
	}
};
