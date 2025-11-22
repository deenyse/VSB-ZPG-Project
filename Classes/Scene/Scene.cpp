#include "Scene.h"

#include "Shader/ShaderFactory.h"

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

void Scene::setSelectedObject(GLuint id) {
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
	return object;
}



void Scene::renderAll(float dt) {
	if (skydome) {
		ShaderFactory::getShader(skydome->getShaderType())->useProgram();
		glDepthMask(GL_FALSE);
		skydome->preDrawUpdate(dt);
		skydome->draw();
		glDepthMask(GL_TRUE);
		glUseProgram(0);

	}

	glStencilMask(0xFF);

	for (auto& [shaderType, objs] : objects) {
		for (auto obj : objs) {
			obj->preDrawUpdate(dt);
		}

		ShaderFactory::getShader(shaderType)->useProgram(); // use the shader program of this group of objects
		for (auto obj : objs) {

			glStencilFunc(GL_ALWAYS, obj->getID(), 0xFF);
			glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

			obj->draw();
		}
		glUseProgram(0);
	}

}

void Scene::spawnObject(glm::vec3 position) {
	auto o = new DrawableObject(ModelSources::Tree, ShaderType::Phong, new Texture(glm::vec3(0, 1, 1)), Materials::Wood);
	o->moveObject(position);
	addObject(o);
	setSelectedObject(o->getID());
}
