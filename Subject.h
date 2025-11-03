#pragma once

#include <vector>

#include "Observer.h"
#include "EnumObservableSubjects.h"

class Subject
{
protected:
	std::vector<Observer*> observers;

public:
	Subject() = default;
	~Subject() = default;

	void notify(ObservableSubjects subject);
	void attach(Observer* observer);
}; 