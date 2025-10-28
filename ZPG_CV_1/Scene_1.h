#pragma once
#include "Scene.h"


#include "Translate.h"
#include "Models/sphere.h"


class Scene_1 : public Scene
{
private:
	void initLights() override;
	void initObjects() override;
public:
	Scene_1() {
		initLights();
		initObjects();
	}
};

