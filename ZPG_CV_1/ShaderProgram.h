#pragma once
#include <string>
#include <vector>
//Include GLEW
#include <GL/glew.h>

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/vec3.hpp> // glm::vec3

#include "Shader.h"
#include "Observer.h"

#include "Camera.h"
#include "Light.h"
class ShaderProgram : public Observer
{
private: 
	GLuint idShaderProgram = 0;
	Camera* camera = nullptr;
	std::vector<Light*> lights;
public:
	ShaderProgram(Shader* vertexShader, Shader* fragmentShader, Camera* camera, std::vector<Light*> lights);
	void setUniform(const GLchar* name, glm::mat4 value);
	void setUniform(const GLchar* name, glm::vec3 value);
	void useProgram();
	void update(SubjectsEnum subject) override;
};

