#pragma once
#include <stdio.h>

//Include GLEW
#include <GL/glew.h>

class Shader
{
private:
	GLuint shaderID = 0;
public:
	Shader(GLenum shaderType, const char* source);
	void attachShader(GLuint shaderProgram);
};

