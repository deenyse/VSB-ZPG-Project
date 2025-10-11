#include "ShaderProgram.h"
#include <stdio.h>
#include <iostream>
#include <string>



ShaderProgram::ShaderProgram(Shader* vertexShader, Shader* fragmentShader)
{	
	// Link shaders to create a shader program
	idShaderProgram = glCreateProgram();
	vertexShader->attachShader(idShaderProgram);
	fragmentShader->attachShader(idShaderProgram);


	glLinkProgram(idShaderProgram);
}

void ShaderProgram::setUniform(const GLchar* name, glm::mat4 value) {
	GLint id = glGetUniformLocation(idShaderProgram, name);

	if (id == -1) {
		std::cerr << "Could not bind uniform "<< name << std::endl;
	}

	//location, count, transpose, *value
	glUniformMatrix4fv(id, 1, GL_FALSE, &value[0][0]);
}

void ShaderProgram::setUniform(const GLchar* name, glm::vec3 value) {
	GLint id = glGetUniformLocation(idShaderProgram, name);

	if (id == -1) {
		std::cerr << "Could not bind uniform " << name << std::endl;
	}
	glUniform3f(id, value.x, value.y, value.z);
}

void ShaderProgram::useProgram() {
	glUseProgram(idShaderProgram);


}