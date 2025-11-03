#pragma once
#include "Scene.h"
#include "StructShaderSources.h"

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

