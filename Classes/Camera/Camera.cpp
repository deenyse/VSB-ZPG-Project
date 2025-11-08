#include "Camera.h"

Camera::Camera(const glm::vec3& eye, const glm::vec3& up)
    : eye(eye), up(up), alpha(0.0f), fi(0.0f) {
	// init target vector
    target = glm::vec3(0.0f, 0.0f, -1.0f);
    viewMatrix = glm::lookAt(eye, eye + target, up);

}

glm::mat4 Camera::getViewMatrix() {
    // Update view matrix
    viewMatrix = glm::lookAt(eye, eye + target, up);
    return viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix() {
    // Projection perspective: FOV=60°, near plane =0.1, far plane=100
    projectionMatrix = glm::perspective(glm::radians(60.0f), screenAspectRatio, 0.1f, 100.0f);
    return projectionMatrix;
}

glm::vec3 Camera::getPosition() {
    return eye;
}

glm::vec3 Camera::getTarget() {
    return target;
}

void Camera::updateOrientation(glm::vec2 mouseOffset, float deltaTime) {
    // Update angles based on mouse movement
    alpha += mouseOffset.x * mouseSensitivity * deltaTime;
    fi += mouseOffset.y * mouseSensitivity * deltaTime;

    // Horizontal cyclic rotation
    const float TWO_PI = glm::radians(360.0f);
    alpha = std::fmod(alpha, TWO_PI);
    if (alpha < 0.0f) alpha += TWO_PI;

    // Vertical rotation limit
    fi = glm::clamp(fi, -glm::radians(89.0f), glm::radians(89.0f));

    // Calculate new target vector
    target.x = cos(fi) * sin(alpha);
    target.y = sin(fi);
    target.z = -cos(fi) * cos(alpha);

    // Notify observers
    notify(ObservableSubjects::SCamera);
}

void Camera::updateScreenSize(int width, int height) {
    screenAspectRatio = width / (float)height;
    notify(ObservableSubjects::SCamera);
}

void Camera::forward(float deltaTime) {
	this->eye += glm::normalize(glm::vec3(this->target)) * movementSpeed * deltaTime;
    notify(ObservableSubjects::SCamera);
}

void Camera::left(float deltaTime) {
	this->eye -= glm::normalize(glm::cross(glm::vec3(this->target), glm::vec3(this->up))) * movementSpeed * deltaTime;
    notify(ObservableSubjects::SCamera);
}

void Camera::backward(float deltaTime) {
	this->eye -= glm::normalize(glm::vec3(this->target)) * movementSpeed * deltaTime;
    notify(ObservableSubjects::SCamera);
}

void Camera::right(float deltaTime) {
	this->eye += glm::normalize(glm::cross(glm::vec3(this->target), glm::vec3(this->up))) * movementSpeed * deltaTime;
    notify(ObservableSubjects::SCamera);
}
