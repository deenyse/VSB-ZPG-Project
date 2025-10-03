#pragma once
//Include GLEW
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  

//Include the standard C++ headers
#include <vector>

//Include Model class
#include "Model.h"
//class Model;

class Model;

class App
{
private:
	GLFWwindow* window=0;

	std::vector<Model*> models;

public:
	void init();
	void createModels();
	void run();
	~App();
};

