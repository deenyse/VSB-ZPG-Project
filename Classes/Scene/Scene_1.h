#pragma once
#include "Scene.h"


#include "../Transformation/Transform.h"
#include "../Transformation/RandomTranslation.h"

#include "../../Models/sphere.h"

#include "../Light/PointLight.h"
#include "../Light/DirectionalLight.h"
#include "../Light/SpotLight.h"
#include "../Light/HeadLight.h"
#include "../Light/FollowingLight.h"

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

