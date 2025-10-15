#include "InputManager.h"


void InputManager::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		inputManager->sceneManager->handleBtnPress(key);
	}

	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}
void InputManager::window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }
void InputManager::window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }
void InputManager::window_size_callback(GLFWwindow* window, int width, int height) {
	InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));

	inputManager->sceneManager->handleScreenResize(width, height);
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}
void InputManager::cursor_callback(GLFWwindow* window, double x, double y) {
	InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));

	if (inputManager->firstMouse) {
		inputManager->lastMousePos = glm::vec2(x, y);
		inputManager->firstMouse = false;
	}

	float deltaX = static_cast<float>(x - inputManager->lastMousePos.x);
	float deltaY = static_cast<float>(inputManager->lastMousePos.y - y); // Inversiion Y
	inputManager->lastMousePos = glm::vec2(x, y);
	
	if (inputManager->sceneManager && inputManager->isCursorLocked)
		inputManager->sceneManager->handleMouseMovement(deltaX, deltaY);

	//printf("Mouse callback %f, %f\n", deltaX, deltaY);
}
void InputManager::button_callback(GLFWwindow* window, int button, int action, int mode) {
	InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		inputManager->isCursorLocked = !inputManager->isCursorLocked;

		if (inputManager->isCursorLocked) {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			inputManager->firstMouse = true; 
			printf("Cursor locked\n");
		}
		else {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			printf("Cursor unlocked\n");
		}
	}

	if (action == GLFW_PRESS) {
		printf("button_callback [%d,%d,%d]\n", button, action, mode);

	}
}


InputManager::InputManager(GLFWwindow* win, SceneManager* sceneManager) {
	window = win;
	this->sceneManager = sceneManager;


	firstMouse = true;
	lastMousePos = glm::vec2(0, 0);

	if (sceneManager) {
		sceneManager->handleMouseMovement(0.0f, 0.0f); 
	}

	//Set the pointer to this class for the callbacks
	glfwSetWindowUserPointer(window, this);



	//Bind the key callbakcs to the window
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_callback);
	glfwSetMouseButtonCallback(window, button_callback);
	glfwSetWindowFocusCallback(window, window_focus_callback);
	glfwSetWindowIconifyCallback(window, window_iconify_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);
}