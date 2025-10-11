#pragma once
//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
//#include <glm/vec4.hpp> // glm::vec4
//#include <glm/mat4x4.hpp> // glm::mat4
//#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <vector>
class Camera
{
private:
	glm::vec3 eye; //camera location
	glm::vec3 target;//view direction vector
	glm::vec3 up;// up vec
	float alpha;// horisontal rotational angle
	float fi;// vertical rotation angle
	glm::mat4 viewMatrix = 0; //view matrix
	glm::mat4 projectionMatrix= 0;// projection matrics
	//std::vector<Observer> liteners;
public:
	Camera(const glm::vec3& eye, const glm::vec3& up);


	// Matrix getter
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix(float aspectRatio);

	// update angle based on mouse orientation
	void updateOrientation(float deltaX, float deltaY);

	/*glm::mat4 getCamera(void) {
		return glm::lookAt(eye, eye + target, up);
	}*/


	// Register Shader Program (Observer)
	/*void attachShaderProgram(ShaderProgram* shaderProgram);
	void detachShaderProgram(ShaderProgram* shaderProgram);
	void notifyShaderPrograms();*/

};

