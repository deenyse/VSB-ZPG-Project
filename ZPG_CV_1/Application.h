#pragma once
//Include GLEW
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  

//Include Model class
#include "Model.h"

//Include the standard C++ headers
#include <vector>

class App
{
private:
	GLuint shaderProgram;
	GLFWwindow* window;

	std::vector<Model*> models;

	GLuint VAO = 0;//TEST

	//Здесь задается вершина. В данном случае vp(VertexPosition) для каждой вершины возвращает ее координаты 
	const char* vertex_shader =
		"#version 330\n"
		"layout(location=0) in vec3 vp;"
		"layout(location=1) in vec3 vc;"

		"out vec3 v_color;"

		"void main () {"
		"     gl_Position = vec4 (vp, 1.0);"
		"	  v_color = vc;"
		"}";

	//Здесь задается цвет фрагмента. В данном случае fragColor для каждой вершины возвращает пурпурный
	const char* fragment_shader =
		"#version 330\n"
		"in vec3 v_color;"
		"out vec4 fragColor;"
		"void main () {"
		"     fragColor = vec4 (v_color, 1.0);"
		"}";
public:
	void init();
	void createShaders();
	void createModels();
	void run();
	~App();
};

