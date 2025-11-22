#include "MultiLightShaderProgram.h"
#include "../Light/DirectionalLight.h"
#include "../Light/PointLight.h"
#include "../Light/SpotLight.h"
#include "../Observer/EnumObservableSubjects.h"


MultiLightShaderProgram::MultiLightShaderProgram(const char* vertex, const char* fragment) : ShaderProgram(vertex, fragment){

}


void MultiLightShaderProgram::attachLightManager(LightManager* lm) {
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

void MultiLightShaderProgram::update(ObservableSubjects subject) {
    useProgram();

	switch (subject) {
		case ObservableSubjects::SCamera: {
			setUniform("viewMatrix", camera->getViewMatrix());
			setUniform("projectionMatrix", camera->getProjectionMatrix());
			setUniform("viewPosition", camera->getPosition());
			break;
		}
		case ObservableSubjects::SLight: {
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
