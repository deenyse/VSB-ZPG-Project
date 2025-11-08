#include "Application.h"
#include "InputManager.h"//Do i need here this declaration?


//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>


#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective



App::App() {

	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	//Init correct GLFW version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


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


	sceneManager = new SceneManager();

	inputManager = new InputManager(window, sceneManager);
	//Set the pointer to this class for the callbacks
	glfwSetWindowUserPointer(window, inputManager);

}

void App::run() {
	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// update other events like input handling
		glfwPollEvents();

		sceneManager->updateCameraPosition(inputManager->getMoveDirection(), inputManager->getAndResetMouseOffset(), inputManager->getDeltaTime());

		sceneManager->renderCurrentScene();


		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);

	}
}


//Callback functions
void App::error_callback(int error, const char* description) { fputs(description, stderr); }


App::~App() {
	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}