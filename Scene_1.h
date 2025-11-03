#pragma once
#include "Scene.h"


#include "Translate.h"
#include "RandomTranslation.h"

#include "Models/sphere.h"

#include "PointLight.h"
#include "DirectionalLight.h"
#include "SpotLight.h"
#include "HeadLight.h"
#include "FollowingLight.h"
class Scene_1 : public Scene
{
private:
	void initLights() override;
	void initObjects() override;
public:
	Scene_1() {
		initScene();
	}
};

