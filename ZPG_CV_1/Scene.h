#pragma once

#include <vector>
#include "DrawableObject.h"

class Scene
{
private:
	std::vector<DrawableObject*> objects;
public:
	
	DrawableObject* addObject(DrawableObject* object);
	void renderAll();
};

