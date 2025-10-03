#pragma once
//Include GLEW
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  

#include <iostream>



class ShaderProgram {
private:
	GLuint idShaderProgram =0;

public:
	~ShaderProgram();

	void create(const char* vertex_shader, const char* fragment_shader);

	void useProgram();
};