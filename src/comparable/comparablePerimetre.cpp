#include "comparable/comparablePerimetre.hpp"

namespace comparable {

string ComparablePerimetre::toString() const {
	return "Perimetre";
}

int ComparablePerimetre::compare(const Figure *f1, const Figure *f2) const {
	return (f1->perimetre() - f2->perimetre());
}

}
