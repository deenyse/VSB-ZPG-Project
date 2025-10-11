#include "Camera.h"

Camera::Camera(const glm::vec3& eye, const glm::vec3& up)
    : eye(eye), up(up), alpha(0.0f), fi(0.0f) {
	// init target vector
    target = glm::vec3(0.0f, 0.0f, -1.0f);
    viewMatrix = glm::lookAt(eye, eye + target, up);

}

glm::mat4 Camera::getViewMatrix() {
    return viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix(float aspectRatio) {
    // Projection perspective: FOV=60°, near plane =0.1, far plane=100
    projectionMatrix = glm::perspective(glm::radians(60.0f), aspectRatio, 0.1f, 100.0f);
    return projectionMatrix;
}

void Camera::updateOrientation(float deltaX, float deltaY) {
	// Update angles based on mouse movement
    alpha += deltaX * 0.01f; // Mouse sensivity
    fi += deltaY * 0.01f;

	//angle limits
	alpha = glm::mod(alpha, glm::radians(360.0f)); // Cyclic horizontal rotation
	fi = glm::clamp(fi, -glm::radians(89.0f), glm::radians(89.0f)); // vertical rotation limit 

	// Calculating new target vector
    target.x = sin(alpha) * cos(fi);
    target.z = sin(alpha) * sin(fi);
    target.y = cos(alpha);

	// Update view matrix
    viewMatrix = glm::lookAt(eye, eye + target, up);

    // notify observers
    //notifyShaderPrograms();
}


//void Camera::attachShaderProgram(ShaderProgram* shaderProgram) {
//    observers.push_back(shaderProgram);
//}
//
//void Camera::detachShaderProgram(ShaderProgram* shaderProgram) {
//    observers.erase(std::remove(observers.begin(), observers.end(), shaderProgram), observers.end());
//}
//
//void Camera::notifyShaderPrograms() {
//    for (auto* shaderProgram : observers) {
//        shaderProgram->updateCameraMatrices();
//    }
//}