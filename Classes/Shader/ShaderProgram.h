#pragma once
#include <string>
#include <vector>
//Include GLEW
#include <GL/glew.h>

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/vec3.hpp> // glm::vec3

#include "EnumShaderType.h"
#include "../Observer/Observer.h"
#include "../Observer/EnumObservableSubjects.h"
#include "../Light/LightManager.h"
#include "../Camera/Camera.h"

#include "../Material/StructMaterialData.h"
class ShaderProgram : public Observer
{
protected:
	GLuint idShaderProgram = 0;
	Camera* camera = nullptr;
public:
	ShaderProgram(const char* vertex, const char* fragment);
	void setUniform(const GLchar* name, glm::mat4 value);
	void setUniform(const GLchar* name, glm::vec3 value);
	void setUniform(const GLchar* name, int value);
	void setUniform(const GLchar* name, float value);
	void setUniform(const GLchar* name, bool value);
	virtual void setUniform(const GLchar* name, const MaterialData* value);
	void useProgram();
	void attachCamera(Camera* cam);

	virtual ShaderType getShaderType() =0;
	virtual void attachLightManager(LightManager*) {};
};

