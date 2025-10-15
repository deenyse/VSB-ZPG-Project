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

void Camera::updateOrientation(float deltaX, float deltaY) {
	// Update angles based on mouse movement
    alpha += deltaX * mouseSensitivity; // Mouse sensivity
    fi += deltaY * mouseSensitivity;

	//angle limits
	alpha = glm::mod(alpha, glm::radians(360.0f)); // Cyclic horizontal rotation
	fi = glm::clamp(fi, -glm::radians(89.0f), glm::radians(89.0f)); // vertical rotation limit 

	// Calculating new target vector
    target.x = cos(fi) * sin(alpha);
    target.y = sin(fi);
    target.z = -cos(fi) * cos(alpha);
	

    //notify observers
    notify();
}

void Camera::updateScreenSize(int width, int height) {
    screenAspectRatio = width / (float)height;
    notify();
}

void Camera::forward() {
	this->eye += glm::normalize(glm::vec3(this->target)) * movementSpeed;
    notify();
}

void Camera::left() {
	this->eye -= glm::normalize(glm::cross(glm::vec3(this->target), glm::vec3(this->up))) * movementSpeed;
    notify();
}

void Camera::backward() {
	this->eye -= glm::normalize(glm::vec3(this->target)) * movementSpeed;
    notify();
}

void Camera::right() {
	this->eye += glm::normalize(glm::cross(glm::vec3(this->target), glm::vec3(this->up))) * movementSpeed;
    notify();
}
