#pragma once

#include "Observer.h"
#include <vector>
class Subject
{
protected:
	std::vector<Observer*> observers;
public:
	Subject() = default;
	~Subject() = default;

	void attach(Observer* observer);

	void notify();
};