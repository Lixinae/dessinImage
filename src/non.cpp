#include "non.hpp"

namespace condition {

Non::Non(Condition *c) : condition(c) {
	
}
    
Non::Non(const Non &other) : condition(other.condition) {
	
}

string Non::toString() const {
	return "NON " + condition->toString();
}

bool Non::verif(const Figure *f) const {
	return !(condition->verif(f));
}

Non &Non::operator=(const Non &other) {
	if (&other != this) {
		condition = other.condition;
	}
	return *this;
}