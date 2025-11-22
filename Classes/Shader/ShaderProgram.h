#pragma once
#include <string>
#include <vector>
//Include GLEW
#include <GL/glew.h>

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/vec3.hpp> // glm::vec3

#include "EnumShaderType.h"
#include "../Shader/ShaderPair.h"
#include "../Observer/Observer.h"

#include "../Camera/Camera.h"

#include "Light/LightManager.h"
#include "../Material/StructMaterialData.h"
class ShaderProgram : public Observer
{
private:
	ShaderType shaderType;
	GLuint idShaderProgram = 0;
	Camera* camera = nullptr;
	LightManager* lightManager = nullptr;
public:
	ShaderProgram(const ShaderPair* shaderSource);
	void setUniform(const GLchar* name, glm::mat4 value);
	void setUniform(const GLchar* name, glm::vec3 value);
	void setUniform(const GLchar* name, int value);
	void setUniform(const GLchar* name, float value);
	void setUniform(const GLchar* name, bool value);
	void setUniform(const GLchar* name, const MaterialData* value);
	ShaderType getShaderType();
	void useProgram();
	void update(ObservableSubjects subject) override;
	void attachCamera(Camera* cam);
	void attachLightManager(LightManager* lm);

};

