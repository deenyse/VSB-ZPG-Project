#include "ShaderProgram.h"
#include <stdio.h>
#include <iostream>
#include <string>

#include "Camera.h"

ShaderProgram::ShaderProgram(Shader* vertexShader, Shader* fragmentShader, Camera * camera)
{	
	this->camera = camera;

	// Link shaders to create a shader program
	idShaderProgram = glCreateProgram();
	vertexShader->attachShader(idShaderProgram);
	fragmentShader->attachShader(idShaderProgram);
	
	GLint status;
	glLinkProgram(idShaderProgram);

	glGetProgramiv(idShaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) {
		GLint infoLogLength;
		glGetProgramiv(idShaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(idShaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Link failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
	if (camera) {
		camera->attach(this);
	}
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

void ShaderProgram::update() {
	if (camera) {
		useProgram();
		setUniform("viewMatrix", camera->getViewMatrix());
		setUniform("projectionMatrix", camera->getProjectionMatrix()); 
	}
}