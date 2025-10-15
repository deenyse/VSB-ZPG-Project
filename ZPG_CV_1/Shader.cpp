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

Shader::Shader(GLenum shaderType, const char* source) {
	compileShader(shaderType, source);
}

Shader::Shader(GLenum shaderType, const std::string filePath) {


    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open shader file: " << filePath << std::endl;
        return;
    }

	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string source = buffer.str();
    
	compileShader(shaderType, source.c_str());
}


void Shader::attachShader(GLuint shaderProgram) {
	glAttachShader(shaderProgram, shaderID);
}