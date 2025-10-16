#pragma once
#include "SubjectsEnum.h"

class Observer
{
public:
	virtual void update(SubjectsEnum Subject) = 0;
};

