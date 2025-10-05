#pragma once
//Include GLEW
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  

//Include the standard C++ headers
#include <vector>

#include "Scene.h"

class Model;

class App
{
private:
	GLFWwindow* window=0;

	std::vector<Scene*> scenes;

public:
	void init();
	void createScenes();
	void run();
	~App();
};

