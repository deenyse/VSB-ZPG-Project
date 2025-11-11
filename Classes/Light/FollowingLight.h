#pragma once
#include "PointLight.h"
#include "../Observer/Observer.h"
#include "../Object/DrawableObject.h"


class FollowingLight : public PointLight, public Observer
{
private:
	void update(ObservableSubjects subject) override;
	DrawableObject* target = nullptr;

public:
	void follow(DrawableObject*);
	FollowingLight(const glm::vec3& col, float c = 1.0f, float l = 0.09f, float q = 0.032f);
};

