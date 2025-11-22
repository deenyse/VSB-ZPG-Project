#include "ShaderProgram.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "Shader.h"



ShaderProgram::ShaderProgram(const char* vertex, const char* fragment)
{
	Shader* vertexShader = new Shader(GL_VERTEX_SHADER, vertex);
	Shader* fragmentShader = new Shader(GL_FRAGMENT_SHADER, fragment);

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

	useProgram();
	setUniform("textureUnitID", 0);
	glUseProgram(0);
}

void ShaderProgram::attachCamera(Camera* cam) {
	if (!cam) return;
	if (camera)
		camera->detach(this);
	camera = cam;
	camera->attach(this);
	update(ObservableSubjects::SCamera);
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

void ShaderProgram::setUniform(const GLchar* name, int value) {
	GLint id = glGetUniformLocation(idShaderProgram, name);

	if (id == -1) {
		std::cerr << "Could not bind uniform " << name << std::endl;
	}

	glUniform1i(id, value);
}

void ShaderProgram::setUniform(const GLchar* name, float value) {
	GLint id = glGetUniformLocation(idShaderProgram, name);

	if (id == -1) {
		std::cerr << "Could not bind uniform " << name << std::endl;
	}

	glUniform1f(id, value);
}

void ShaderProgram::setUniform(const GLchar* name, bool value) {
	GLint id = glGetUniformLocation(idShaderProgram, name);

	if (id == -1) {
		std::cerr << "Could not bind uniform " << name << std::endl;
		return;
	}

	glUniform1i(id, static_cast<GLint>(value));
}

void ShaderProgram::setUniform(const GLchar* name, const MaterialData* value) {
	std::string base = std::string(name) + ".";

	setUniform((base + "ra").c_str(), value->ra);
	setUniform((base + "rd").c_str(), value->rd);
	setUniform((base + "rs").c_str(), value->rs);
	setUniform((base + "h").c_str(),  value->h);
}


void ShaderProgram::useProgram() {
	glUseProgram(idShaderProgram);
}

