#include "ShaderProgram.h"

ShaderProgram::~ShaderProgram() {
		glDeleteProgram(idShaderProgram);
	}

void ShaderProgram::create(const char* vertex_shader, const char* fragment_shader) {
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
	glCompileShader(fragmentShader);

	idShaderProgram = glCreateProgram();
	glAttachShader(idShaderProgram, fragmentShader);
	glAttachShader(idShaderProgram, vertexShader);
	glLinkProgram(idShaderProgram);

	GLint status;
	glGetProgramiv(idShaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(idShaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(idShaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

void ShaderProgram::useProgram() {
	glUseProgram(idShaderProgram);
}
