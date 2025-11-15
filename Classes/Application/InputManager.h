#pragma once
//Include GLEW
#include <GL/glew.h>

//Include GLFW  
#include <GLFW/glfw3.h>  

#include <glm/vec2.hpp> // glm::vec2

#include <stdlib.h>
#include <stdio.h>

#include "../Scene/SceneManager.h"

#include "EnumMooveDirections.h"

class InputManager
{
private:
	GLFWwindow* window = 0;
	SceneManager* sceneManager= nullptr;

	// Mouse temp handler
	glm::vec2 lastMousePos;
	bool firstMouse = true; 
	bool isCursorLocked = false;
	//Camera movement
	int moveDirection = 0;
	float lastFrameTime;           // Time of the last frame (for delta time)
	glm::vec2 mouseOffset; // store accumulated mouse movement

	glm::vec3 lastClickWordCords = glm::vec3(0);

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_size_callback(GLFWwindow* window, int width = 1, int height = 1);
	static void cursor_callback(GLFWwindow* window, double x, double y);
	static void button_callback(GLFWwindow* window, int button, int action, int mode);

public:
	float getDeltaTime();
	int getMoveDirection();
	glm::vec2 getAndResetMouseOffset();
	InputManager(GLFWwindow* win, SceneManager* sceneManager);

};

