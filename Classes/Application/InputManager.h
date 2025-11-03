#pragma once
//Include GLEW
#include <GL/glew.h>

//Include GLFW  
#include <GLFW/glfw3.h>  

#include <glm/vec2.hpp> // glm::vec2

#include <stdlib.h>
#include <stdio.h>

#include "SceneManager.h"


class InputManager
{
private:
	GLFWwindow* window = 0;
	SceneManager* sceneManager= NULL;

	// Mouse temp handler
	glm::vec2 lastMousePos;
	bool firstMouse = true; 
	bool isCursorLocked = false;

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void cursor_callback(GLFWwindow* window, double x, double y);
	static void button_callback(GLFWwindow* window, int button, int action, int mode);

public:

	InputManager(GLFWwindow* win, SceneManager* sceneManager);

};

