#include "Scene.h"

Scene::Scene() {
	lightManager->addLight(headLight);
}

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

DrawableObject* Scene::addObject(DrawableObject * object) {
	if (dynamic_cast<Skydome*>(object)) {
		skydome = dynamic_cast<Skydome*>(object);
		return skydome;
	}
	object->setId(objects.size() + 1);
	objects.push_back(object);
	return object;
}



void Scene::renderAll() {
	if (skydome) {
		glDepthMask(GL_FALSE);
		skydome->draw();
		glDepthMask(GL_TRUE);
	}
	// 2. Clear stensill before objects
	// glClear(GL_STENCIL_BUFFER_BIT);

	glStencilMask(0xFF);
	for (auto obj : objects) {

		glStencilFunc(GL_ALWAYS, obj->getID(), 0xFF);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

		obj->draw();
	}

}

