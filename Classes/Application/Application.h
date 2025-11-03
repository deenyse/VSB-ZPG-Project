#pragma once
//Include GLEW
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  

//Include the standard C++ headers
#include <vector>

#include "../Scene/Scene.h"
#include "../Scene/SceneManager.h"
#include "InputManager.h"

class App
{
private:
	static void error_callback(int error, const char* description);


	GLFWwindow* window=0;
	SceneManager* sceneManager = NULL;
	InputManager* inputManager = NULL;

public:
	App();
	void run();
	~App();
};

