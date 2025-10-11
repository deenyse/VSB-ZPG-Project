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
	// Mouse temp handler
	glm::vec2 lastMousePos;
	bool firstMouse = true; // Перший рух миші

	GLFWwindow* window=0;
	std::vector<Scene*> scenes;
	Scene* currentScene = NULL;

	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void cursor_callback(GLFWwindow* window, double x, double y);
	static void button_callback(GLFWwindow* window, int button, int action, int mode);

public:
	void init();
	void createScenes();
	void setScene(int i);
	void run();
	~App();
};

