#include "ConstantShaderProgram.h"


ConstantShaderProgram::ConstantShaderProgram() : ShaderProgram("ShaderSource/constant.vert","ShaderSource/constant.frag"){

}

void ConstantShaderProgram::update(ObservableSubjects subject) {
	useProgram();

	if (subject == ObservableSubjects::SCamera) {
		setUniform("viewMatrix", camera->getViewMatrix());
		setUniform("projectionMatrix", camera->getProjectionMatrix());
	}

	glUseProgram(0);
}

ShaderType ConstantShaderProgram::getShaderType() {
	return ShaderType::Constant;
}