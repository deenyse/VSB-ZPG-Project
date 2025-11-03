#pragma once
#include "Scene.h"

//Transformations
#include "../Transformation/Scale.h"
#include "../Transformation/Translate.h"
#include "../Transformation/Rotate.h"
#include "../Transformation/RandomTranslation.h"

//Lights
#include "../Light/DirectionalLight.h"
#include "../Light/FollowingLight.h"

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

