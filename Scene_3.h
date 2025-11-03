#pragma once
#include "Scene.h"

//Transformations
#include "Scale.h"
#include "Translate.h"
#include "Rotate.h"
#include "RandomTranslation.h"

//Lights
#include "DirectionalLight.h"
#include "FollowingLight.h"

class Scene_3 : public Scene
{
private:
	void initLights() override;
	void initObjects() override;
public:
	Scene_3() {
		initScene();
	}
};

