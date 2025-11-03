#pragma once
//Include GLEW
#include <GL/glew.h>

#include <stdio.h>
#include <vector>
class Model
{
protected:
	GLuint VBO, VAO;
	int verticesNum = 0;
	void setupBuffers();
	std::vector<float> vertices;
public:
	Model(const float* points, int verticesNum);
	Model(const std::vector<float>& points);
	void bind() {
		glBindVertexArray(VAO);
	}
};
