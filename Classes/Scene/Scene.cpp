#include "Scene.h"

Scene::Scene() {
	lightManager->addLight(headLight);
}

Camera* Scene::getCamera()  { return camera; }

void Scene::switchHeadLight() {
	headLight->isOn = !headLight->isOn;
	headLight->notify(ObservableSubjects::SLight);
}

void Scene::setSelectedObject(GLuint id) {
	for (auto o : objects) {
		if (o->getID() == id) {
			selectedObject = o;
		}
	}
}

DrawableObject *Scene::getSelectedObject()  { return selectedObject; }


DrawableObject* Scene::addObject(DrawableObject * object) {
	if (dynamic_cast<Skydome*>(object)) {
		skydome = dynamic_cast<Skydome*>(object);
		return skydome;
	}
	object->setId(objects.size() + 1);
	objects.push_back(object);
	return object;
}



void Scene::renderAll(float dt) {
	if (skydome) {
		glDepthMask(GL_FALSE);
		skydome->draw(dt);
		glDepthMask(GL_TRUE);
	}

	glStencilMask(0xFF);
	for (auto obj : objects) {

		glStencilFunc(GL_ALWAYS, obj->getID(), 0xFF);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

		obj->draw(dt);
	}

}

void Scene::spawnObject(glm::vec3 position) {
	auto o = new DrawableObject(ModelSources::Tree, getCamera(), ShaderSources::Phong, lightManager, new Texture(glm::vec3(0, 1, 1)), Materials::Wood);
	o->moveObject(position);
	addObject(o);
	setSelectedObject(o->getID());
}
