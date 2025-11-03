#pragma once
#include "Scene.h"

#include "../Transformation/Scale.h"

class Scene_2 : public Scene
{
	private:
		void initLights() override;
		void initObjects() override;
public:
	Scene_2() {
		initScene();
	}
};

