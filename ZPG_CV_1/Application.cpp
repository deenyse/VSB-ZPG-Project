#include "Application.h"



//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

#include "Scene_1.h"
#include "Scene_2.h"
#include "Scene_3.h"

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective


//Callback functions
void App::error_callback(int error, const char* description) { fputs(description, stderr); }
void App::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//Get the pointer to the application class
	App* app = static_cast<App*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_1)
			app->setScene(1);
		else if (key == GLFW_KEY_2)
			app->setScene(2);
		else if (key == GLFW_KEY_3)
			app->setScene(3);
	}

	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}
void App::window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }
void App::window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }
void App::window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}
void App::cursor_callback(GLFWwindow* window, double x, double y) { printf("cursor_callback \n"); }
void App::button_callback(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}


void App::init() {

	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); //vsync


	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();
	glEnable(GL_DEPTH_TEST);//Do depth comparisons and update the depth buffer.


	// get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);

	//Set the pointer to this class for the callbacks
	glfwSetWindowUserPointer(window, this);

	//Init correct GLFW version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Bind the key callbakcs to the window
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_callback);
	glfwSetMouseButtonCallback(window, button_callback);
	glfwSetWindowFocusCallback(window, window_focus_callback);
	glfwSetWindowIconifyCallback(window, window_iconify_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);

}



void App::createScenes() {
	scenes.push_back(new Scene_1());
	scenes.push_back(new Scene_2());
	scenes.push_back(new Scene_3());

	currentScene = scenes[2];
}
void App::setScene(int i) {
	if (i < 1 || i > scenes.size()) return;
	currentScene = scenes[i - 1];
	printf("Switched to scene %d \n", i);
}

void App::run() {
	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glUseProgram(shaderProgram);

		if (currentScene)
			currentScene->renderAll();


		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}
}




App::~App() {
	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}