#include "Subject.h"


void Subject::attach(Observer* observer) {
	observer->update(SubjectsEnum::SCamera);
	observers.push_back(observer);
}


void Subject::notify(SubjectsEnum subject) {
	for (auto* observer : observers) {
		observer->update(subject);
	}
}