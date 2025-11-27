#include "Scene.h"

#include "Shader/ShaderFactory.h"
#include "Shader/MultiLightShaderProgram.h"
#include "Texture/Textures.h"

Scene::Scene() {
	lightManager->addLight(headLight);
}

Camera* Scene::getCamera()  { return camera; }


void Scene::bindCameraAndLightToUsedShaders() {
	if (skydome)
		ShaderFactory::getShader(skydome->getShaderType())->attachCamera(camera);
	for (auto& [shaderType, _] : objects) {
		auto shaderProgram = ShaderFactory::getShader(shaderType);
		shaderProgram->attachCamera(camera);
		shaderProgram->attachLightManager(lightManager);
	}
}

void Scene::switchHeadLight() {
	headLight->isOn = !headLight->isOn;
	headLight->notify(ObservableSubjects::SLight);
}

void Scene::onObjectSelect(GLuint id) {
	for (auto& [shaderType, objs] : objects) {
		for (auto o : objs) {
			if (o->getID() == id) {
				selectedObject = o;
			}
		}
	}
}

DrawableObject *Scene::getSelectedObject()  { return selectedObject; }


DrawableObject* Scene::addObject(DrawableObject * object) {
	if (dynamic_cast<Skydome*>(object)) {
		skydome = dynamic_cast<Skydome*>(object);
		return skydome;
	}
	objects[object->getShaderType()].push_back(object);
	auto shaderProgram = ShaderFactory::getShader(object->getShaderType());
	shaderProgram->attachCamera(camera);
	shaderProgram->attachLightManager(lightManager);
	return object;
}
Light* Scene::addLight(Light * light) {
	lightManager->addLight(light);
	return light;
}

void Scene::renderAll(float dt) {
	if (skydome) {
		ShaderFactory::getShader(skydome->getShaderType())->useProgram();
		glDepthMask(GL_FALSE);
		skydome->updateState(dt);
		skydome->draw();
		glDepthMask(GL_TRUE);
		glUseProgram(0);

	}

	glStencilMask(0xFF);

	for (auto& [shaderType, objs] : objects) {
		for (auto obj : objs) {
			obj->updateState(dt);
		}
	}
	for (auto& [shaderType, objs] : objects) {
		ShaderFactory::getShader(shaderType)->useProgram(); // use the shader program of this group of objects
		for (auto obj : objs) {

			glStencilFunc(GL_ALWAYS, obj->getID(), 0xFF);
			glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

			obj->draw();
		}
		glUseProgram(0);
	}
}
void Scene::onPositionAction(glm::vec3 position) {
	printf("Position Action\n");
	auto o = new DrawableObject(Models::Tree, ShaderType::Phong, Textures::Green, Materials::Wood);
	o->moveObject(position);
	addObject(o);
	onObjectSelect(o->getID());
}
