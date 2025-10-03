#pragma once

//Include GLEW
#include <GL/glew.h>

class ShaderProgram
{
private: 
	GLuint idShaderProgram = 0;
public:
	ShaderProgram();
	void useProgram();
};

