#pragma once
#include <stdio.h>

//Include GLEW
#include <GL/glew.h>
#include <string>

#include <sstream>
#include <iostream>
#include <fstream>

class Shader
{
private:
	GLuint shaderID = 0;
	void compileShader(GLenum shaderType, const char* source);
public:
	Shader(GLenum shaderType, const char* shaderFile);
	void attachShader(GLuint shaderProgram);
};

