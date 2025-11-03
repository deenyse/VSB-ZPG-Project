#pragma once
#include <string>
#include <vector>
//Include GLEW
#include <GL/glew.h>

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/vec3.hpp> // glm::vec3

#include "Shader.h"
#include "../Observer/Observer.h"

#include "../Camera/Camera.h"

#include "../Light/Light.h"


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
	void setUniform(const GLchar* name, int value);
	void setUniform(const GLchar* name, float value);
	void setUniform(const GLchar* name, bool value);
	void useProgram();
	void update(ObservableSubjects subject) override;
};

