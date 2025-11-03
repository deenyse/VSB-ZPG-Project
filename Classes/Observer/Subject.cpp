#include "Subject.h"

void Subject::attach(Observer* observer) {
	observers.push_back(observer);
}


void Subject::notify(ObservableSubjects subject) {
	for (auto* observer : observers) {
		observer->update(subject);
	}
}