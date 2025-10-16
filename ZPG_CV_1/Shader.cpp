#include "Shader.h"


void Shader::compileShader(GLenum shaderType, const char* source) {
	// Create and compile shader
	shaderID = glCreateShader(shaderType);
	glShaderSource(shaderID, 1, &source, NULL);
	glCompileShader(shaderID);

	// Check for compilation errors
	GLint status;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(shaderID, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Compilation failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

Shader::Shader(GLenum shaderType, const char* shaderFile) {



	//Loading the contents of a file into a variable
	std::ifstream file(shaderFile);
	if (!file.is_open())
	{
		std::cout << "Unable to open file " << shaderFile << std::endl;
		exit(-1);
	}
	std::string shaderCode((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
   
	compileShader(shaderType, shaderCode.c_str());
}


void Shader::attachShader(GLuint shaderProgram) {
	glAttachShader(shaderProgram, shaderID);
}