#pragma once
//Include GLEW
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  

//Include the standard C++ headers
#include <vector>

#include "DrawableObject.h"

class Model;

class App
{
private:
	GLFWwindow* window=0;

	std::vector<DrawableObject*> models;

public:
	void init();
	void createModels();
	void run();
	~App();
};

