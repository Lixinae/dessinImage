#include "comparable/comparablePerimetre.hpp"

namespace comparateur {

string ComparateurPerimetre::toString() const {
	return "Perimetre";
}

int ComparateurPerimetre::compare(const Figure *f1, const Figure *f2) const {
	return (f1->perimetre() - f2->perimetre());
}

}
