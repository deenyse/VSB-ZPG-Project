#pragma once
#include <string>

//Include GLEW
#include <GL/glew.h>

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/vec3.hpp> // glm::vec3

#include "Shader.h"

class ShaderProgram
{
private: 
	GLuint idShaderProgram = 0;
public:
	ShaderProgram(Shader* vertexShader, Shader* fragmentShader);
	void setUniform(const GLchar* name, glm::mat4 value);
	void setUniform(const GLchar* name, glm::vec3 value);
	void useProgram();
};

