#pragma once

#include <vector>
#include "DrawableObject.h"

#include "Camera.h"
class Scene
{

//protected:
	//Camera* camera = nullptr;
private:
	std::vector<DrawableObject*> objects;
public:
	DrawableObject* addObject(const float* points, int verticiesNum);
	void renderAll();
	Camera* camera = nullptr;

};

