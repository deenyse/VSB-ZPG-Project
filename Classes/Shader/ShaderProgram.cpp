#include "ShaderProgram.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "Shader.h"

#include "../Light/DirectionalLight.h"
#include "../Light/PointLight.h"
#include "../Light/SpotLight.h"

ShaderProgram::ShaderProgram(const ShaderPair* shaderSource)
{
	shaderType = shaderSource->type;
	Shader* vertexShader = new Shader(GL_VERTEX_SHADER, shaderSource->vertex);
	Shader* fragmentShader = new Shader(GL_FRAGMENT_SHADER, shaderSource->fragment);

	// Link shaders to create a shader program
	idShaderProgram = glCreateProgram();
	vertexShader->attachShader(idShaderProgram);
	fragmentShader->attachShader(idShaderProgram);
	
	GLint status;
	glLinkProgram(idShaderProgram);

	glGetProgramiv(idShaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) {
		GLint infoLogLength;
		glGetProgramiv(idShaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(idShaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Link failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}

	useProgram();
	setUniform("textureUnitID", 0);
	glUseProgram(0);
}

void ShaderProgram::attachCamera(Camera* cam) {
	if (!cam) return;
	if (camera)
		camera->detach(this);
	camera = cam;
	camera->attach(this);
	update(ObservableSubjects::SCamera);
}


void ShaderProgram::attachLightManager(LightManager* lm) {
	if (!lm) return;
	if (lightManager)
		for (int i = 0; i < lightManager->getLightsAmount(); i++) {
			lightManager->getLight(i)->detach(this);
		}
	lightManager = lm;
	for (int i = 0; i < lightManager->getLightsAmount(); i++) {
		lightManager->getLight(i)->attach(this);
	}
	update(ObservableSubjects::SLight);
}


void ShaderProgram::setUniform(const GLchar* name, glm::mat4 value) {
	GLint id = glGetUniformLocation(idShaderProgram, name);

	if (id == -1) {
		std::cerr << "Could not bind uniform "<< name << std::endl;
	}

	//location, count, transpose, *value
	glUniformMatrix4fv(id, 1, GL_FALSE, &value[0][0]);
}

void ShaderProgram::setUniform(const GLchar* name, glm::vec3 value) {
	GLint id = glGetUniformLocation(idShaderProgram, name);

	if (id == -1) {
		std::cerr << "Could not bind uniform " << name << std::endl;
	}
	glUniform3f(id, value.x, value.y, value.z);
}

void ShaderProgram::setUniform(const GLchar* name, int value) {
	GLint id = glGetUniformLocation(idShaderProgram, name);

	if (id == -1) {
		std::cerr << "Could not bind uniform " << name << std::endl;
	}

	glUniform1i(id, value);
}

void ShaderProgram::setUniform(const GLchar* name, float value) {
	GLint id = glGetUniformLocation(idShaderProgram, name);

	if (id == -1) {
		std::cerr << "Could not bind uniform " << name << std::endl;
	}

	glUniform1f(id, value);
}

void ShaderProgram::setUniform(const GLchar* name, bool value) {
	GLint id = glGetUniformLocation(idShaderProgram, name);

	if (id == -1) {
		std::cerr << "Could not bind uniform " << name << std::endl;
		return;
	}

	glUniform1i(id, static_cast<GLint>(value));
}

void ShaderProgram::setUniform(const GLchar* name, const MaterialData* value) {
	if (shaderType != ShaderType::Phong)
		return;
	std::string base = std::string(name) + ".";

	setUniform((base + "ra").c_str(), value->ra);
	setUniform((base + "rd").c_str(), value->rd);
	setUniform((base + "rs").c_str(), value->rs);
	setUniform((base + "h").c_str(),  value->h);
}

ShaderType ShaderProgram::getShaderType() {
	return shaderType;
}

void ShaderProgram::useProgram() {
	glUseProgram(idShaderProgram);
}

void ShaderProgram::update(ObservableSubjects subject) {
	useProgram();

	switch (subject) {
		case ObservableSubjects::SCamera: {
			setUniform("viewMatrix", camera->getViewMatrix());
			setUniform("projectionMatrix", camera->getProjectionMatrix());
			if (shaderType == ShaderType::Phong || shaderType == ShaderType::Bling)
				setUniform("viewPosition", camera->getPosition());

			break;
		}
		case ObservableSubjects::SLight: {
			if (shaderType != ShaderType::Phong && shaderType != ShaderType::Bling)
				break;

			setUniform("numberOfLights", lightManager->getLightsAmount());

			for (int i = 0; i < lightManager->getLightsAmount(); i++)
			{
				std::string prefix = "lights[" + std::to_string(i) + "]";

				if (!lightManager->getLight(i)) continue;

				// Set common uniforms
				setUniform((prefix + ".type").c_str(), static_cast<int>(lightManager->getLight(i)->getType()));
				setUniform((prefix + ".color").c_str(), lightManager->getLight(i)->color);
				setUniform((prefix + ".isOn").c_str(), lightManager->getLight(i)->isOn);
				// Set uniforms depending on the light type
				if (lightManager->getLight(i)->getType() == LightType::DIRECTIONAL) {
					DirectionalLight* dirLight = (DirectionalLight*)lightManager->getLight(i);
					setUniform((prefix + ".direction").c_str(), dirLight->direction);
				}
				else if (lightManager->getLight(i)->getType() == LightType::POINT) {
					PointLight* pointLight = (PointLight*)lightManager->getLight(i);
					setUniform((prefix + ".position").c_str(), pointLight->position);
					setUniform((prefix + ".constant").c_str(), pointLight->constant);
					setUniform((prefix + ".linear").c_str(), pointLight->linear);
					setUniform((prefix + ".quadratic").c_str(), pointLight->quadratic);
				}
				else if (lightManager->getLight(i)->getType() == LightType::SPOT) {
					SpotLight* spotLight = (SpotLight*)lightManager->getLight(i);
					setUniform((prefix + ".position").c_str(), spotLight->position);
					setUniform((prefix + ".direction").c_str(), spotLight->direction);
					setUniform((prefix + ".cutOff").c_str(), spotLight->cutOff);
					setUniform((prefix + ".outerCutOff").c_str(), spotLight->outerCutOff);
					setUniform((prefix + ".constant").c_str(), 1.0f);
					setUniform((prefix + ".linear").c_str(), 0.09f);
					setUniform((prefix + ".quadratic").c_str(), 0.032f);
				}
			}

			break;
		}
	}

	glUseProgram(0);
}