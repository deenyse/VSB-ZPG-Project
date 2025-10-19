#include "Subject.h"

void Subject::attach(Observer* observer) {
	observers.push_back(observer);
}


void Subject::notify(SubjectsEnum subject) {
	for (auto* observer : observers) {
		observer->update(subject);
	}
}