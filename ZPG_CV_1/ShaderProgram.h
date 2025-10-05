#pragma once

//Include GLEW
#include <GL/glew.h>

#include <glm/mat4x4.hpp> // glm::mat4


class ShaderProgram
{
private: 
	GLuint idShaderProgram = 0;
	glm::mat4 modelTransform = glm::mat4(1.0f);
	GLint idModelTransform = -1;
public:
	ShaderProgram();
	void setModelTransform(glm::mat4 model);
	void useProgram();
};

