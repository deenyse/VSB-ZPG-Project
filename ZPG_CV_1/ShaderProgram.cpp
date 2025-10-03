#include "ShaderProgram.h"
#include <stdio.h>
#include <iostream>


const char* vertexShaderSource =
"#version 330 core\n"
"layout(location=0) in vec3 vp;"
"layout(location=1) in vec3 vc;"

"out vec3 v_color;"

"void main () {"
"     gl_Position = vec4 (vp, 1.0);"
"	  v_color = vc;"
"}";


const char* fragmentShaderSource =
"#version 330 core\n"
"in vec3 v_color;"
"out vec4 fragColor;"
"void main () {"
"     fragColor = vec4 (v_color, 1.0);"
"}";

ShaderProgram::ShaderProgram() {
	// Create and compile the vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);


	// Create and compile the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);


	// Link shaders to create a shader program
	idShaderProgram = glCreateProgram();
	glAttachShader(idShaderProgram, vertexShader);
	glAttachShader(idShaderProgram, fragmentShader);
	glLinkProgram(idShaderProgram);


	// Check for linking errors
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