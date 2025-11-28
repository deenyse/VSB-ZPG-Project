#pragma once
#include "Scene.h"


#include "../Transformation/Transform.h"
#include "../Transformation/RandomTranslation.h"


#include "../Light/PointLight.h"
#include "../Light/DirectionalLight.h"
#include "../Light/SpotLight.h"
#include "../Light/HeadLight.h"
#include "../Light/FollowingLight.h"
#include "../Transformation/BezierTranslation.h"
class Scene_1 : public Scene
{
private:
    BezierTranslation* bT;
public:
    Scene_1();
    void onPositionUpdateAction(glm::vec3 position) override;
};

