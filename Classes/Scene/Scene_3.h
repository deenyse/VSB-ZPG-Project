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

#include "../Material/StructMaterials.h"


class Scene_3 : public Scene
{
private:
	int points = 0;
	std::vector<GLuint> highValueBalls;
	TextureInstance* yellow;
	TextureInstance* red;
	void spawnNewBall();
public:
	Scene_3() ;
	void onObjectSelect(GLuint id) override;
};

