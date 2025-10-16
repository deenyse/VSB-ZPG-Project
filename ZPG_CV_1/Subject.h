#pragma once

#include <vector>

#include "Observer.h"
#include "SubjectsEnum.h"

class Subject
{
protected:
	std::vector<Observer*> observers;
public:
	Subject() = default;
	~Subject() = default;

	void attach(Observer* observer);

	void notify(SubjectsEnum subject);
}; 