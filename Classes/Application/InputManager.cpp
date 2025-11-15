#include "InputManager.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <cstdio>

// ======================= KEY CALLBACK =======================
void InputManager::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));

    // Close window on ESC
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    // Key press
    if (action == GLFW_PRESS){
        if (key == GLFW_KEY_1)      inputManager->sceneManager->setScene(0);
        else if (key == GLFW_KEY_2) inputManager->sceneManager->setScene(1);
        else if (key == GLFW_KEY_3) inputManager->sceneManager->setScene(2);
        else if (key == GLFW_KEY_W) inputManager->moveDirection |= Direction::Forward;
        else if (key == GLFW_KEY_S) inputManager->moveDirection |= Direction::Backward;
        else if (key == GLFW_KEY_A) inputManager->moveDirection |= Direction::Left;
        else if (key == GLFW_KEY_D) inputManager->moveDirection |= Direction::Right;
    }
    // Key release
    else if (action == GLFW_RELEASE) {
        if (key == GLFW_KEY_W)      inputManager->moveDirection &= ~Direction::Forward;
        else if (key == GLFW_KEY_S) inputManager->moveDirection &= ~Direction::Backward;
        else if (key == GLFW_KEY_A) inputManager->moveDirection &= ~Direction::Left;
        else if (key == GLFW_KEY_D) inputManager->moveDirection &= ~Direction::Right;
        else if (key == GLFW_KEY_F) inputManager->sceneManager->switchHeadLight();
        else if (key == GLFW_KEY_N && inputManager->lastClickWordCords != glm::vec3(0)) inputManager->sceneManager->getCurrentScene()->spawnObject(inputManager->lastClickWordCords);
    }

    if (action == GLFW_PRESS || action == GLFW_REPEAT ) {
        auto selectedObject = inputManager->sceneManager->getCurrentScene()->getSelectedObject();
        if (!selectedObject)
            return;

        if (key == GLFW_KEY_LEFT) selectedObject->moveObject(glm::vec3(-1.f,0.f,0.f));
        else if (key == GLFW_KEY_RIGHT) selectedObject->moveObject(glm::vec3(1.f,0.f,0.f));
        else if (key == GLFW_KEY_DOWN) selectedObject->moveObject(glm::vec3(0.f,0.f,1.f));
        else if (key == GLFW_KEY_UP) selectedObject->moveObject(glm::vec3(0.f,0.f,-1.f));
    }
    printf("key_callback [%d,%d,%d,%d]\n", key, scancode, action, mods);
}

// ======================= WINDOW FOCUS CALLBACK =======================
void InputManager::window_focus_callback(GLFWwindow* window, int focused) {
    InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
    if (focused) {
        inputManager->window_size_callback(window);
        printf("window_focus_callback\n");
    }
}

// ======================= WINDOW ICONIFY CALLBACK =======================
void InputManager::window_iconify_callback(GLFWwindow* window, int iconified) {
    printf("window_iconify_callback\n");
}

// ======================= WINDOW SIZE CALLBACK =======================
void InputManager::window_size_callback(GLFWwindow* window, int width, int height ) {
    InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
    if (!inputManager || !inputManager->sceneManager) return;

    int fbWidth, fbHeight;
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);

    float ratio = fbWidth / static_cast<float>(fbHeight);
    inputManager->sceneManager->handleScreenResize(fbWidth, fbHeight);

    printf("resize window: %d x %d, framebuffer: %d x %d, ratio: %.2f\n",
           width, height, fbWidth, fbHeight, ratio);
}

// ======================= MOUSE CURSOR CALLBACK =======================
void InputManager::cursor_callback(GLFWwindow* window, double x, double y) {
    InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));


    // Initialize first mouse position
    if (inputManager->firstMouse) {
        inputManager->lastMousePos = glm::vec2(x, y);
        inputManager->firstMouse = false;
    }

    // Calculate mouse offset since last frame
    float deltaX = static_cast<float>(x - inputManager->lastMousePos.x);
    float deltaY = static_cast<float>(inputManager->lastMousePos.y - y); // invert Y
    inputManager->lastMousePos = glm::vec2(x, y);

    // Accumulate offset for processing in the main loop
    if (inputManager->isCursorLocked) {
        inputManager->mouseOffset += glm::vec2(deltaX, deltaY);
    }
}

// ======================= MOUSE BUTTON CALLBACK =======================
void InputManager::button_callback(GLFWwindow* window, int button, int action, int mods) {
    InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));

    // Toggle cursor lock with right mouse button
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        inputManager->isCursorLocked = !inputManager->isCursorLocked;

        if (inputManager->isCursorLocked) {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            inputManager->firstMouse = true;
            printf("Cursor locked\n");
        } else {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            printf("Cursor unlocked\n");
        }
    }

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        Scene* scene = inputManager->sceneManager->getCurrentScene();
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        int fbWidth, fbHeight;
        glfwGetFramebufferSize(window, &fbWidth, &fbHeight);

        glm::vec2 cursor(xpos, ypos);

        GLbyte color[4];
        GLfloat depth;
        GLuint index;

        GLint x = (GLint)cursor.x;
        GLint y = (GLint)cursor.y;

        Camera* camera = inputManager->sceneManager->getCurrentScene()->getCamera();

        int newy = fbHeight - y;

        glReadPixels(x, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
        glReadPixels(x, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
        glReadPixels(x, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

        scene->setSelectedObject(index);

        printf("Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx, depth%f, stencil index %u\n", x, y, color[0], color[1], color[2], color[3], depth, index);

        //Můžeme nastavit vybrané těleso scena->setSelect(index-1);

        //Můžeme vypočíst pozici v globálním souřadném systému.
        glm::vec3 screenX = glm::vec3(x, newy, depth);
        glm::mat4 view = camera->getViewMatrix();
        glm::mat4 projection = camera->getProjectionMatrix();


        glm::vec4 viewPort = glm::vec4(0, 0, fbWidth, fbHeight);
        glm::vec3 pos = glm::unProject(screenX, view, projection, viewPort);
        inputManager->lastClickWordCords = pos;

        printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);
    }

    if (action == GLFW_PRESS) {
        printf("button_callback [%d,%d,%d]\n", button, action, mods);
    }
}


// ======================= GET MOVE DIRECTION =======================
int InputManager::getMoveDirection() {
    return moveDirection;
}

glm::vec2 InputManager::getAndResetMouseOffset() {
    glm::vec2 tmpMouseOffset = mouseOffset;
    mouseOffset = glm::vec2(0.0f);
    return tmpMouseOffset;

}


// ======================= DELTA TIME FUNCTION =======================
float InputManager::getDeltaTime() {
    // Get current time
    float currentTime = static_cast<float>(glfwGetTime());
    // Calculate delta time
    float deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;
    return deltaTime;
}

// ======================= CONSTRUCTOR =======================
InputManager::InputManager(GLFWwindow* win, SceneManager* sceneManager) {
    window = win;
    this->sceneManager = sceneManager;

    firstMouse = false;
    lastMousePos = glm::vec2(0, 0);
    lastFrameTime = static_cast<float>(glfwGetTime());
    moveDirection = 0;
    isCursorLocked = false;

    // Set the window user pointer to this instance
    glfwSetWindowUserPointer(window, this);

    // Bind callbacks
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_callback);
    glfwSetMouseButtonCallback(window, button_callback);
    glfwSetWindowFocusCallback(window, window_focus_callback);
    glfwSetWindowIconifyCallback(window, window_iconify_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);
}
