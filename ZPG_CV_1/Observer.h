#pragma once
#include "EnumObservableSubjects.h"

class Observer
{
public:
	virtual void update(ObservableSubjects Subject) = 0;
};

