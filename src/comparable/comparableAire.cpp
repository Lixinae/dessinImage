#include "comparable/comparableAire.hpp"

namespace comparable {

string ComparableAire::toString() const {
	return "Aire";
}

int ComparableAire::compare(const Figure *f1, const Figure *f2) const {
	return (f1->surface() - f2->surface());
}

}
