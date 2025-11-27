#pragma once
//Include GLEW
#include <GL/glew.h>

#include <stdio.h>
#include <vector>
class ModelInstance
{
protected:
	GLuint VBO, VAO = 0;
	int verticesNum = 0;
	void setupBuffers();
	std::vector<float> vertices;
public:
	ModelInstance(const std::vector<float>& points);
	int getVerticesNum();
	void bind();
};
