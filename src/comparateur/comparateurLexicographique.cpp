#include "comparateur/comparateurLexicographique.hpp"

namespace comparateur {

ComparateurLexicographique::ComparateurLexicographique(Comparateur * c1, Comparateur * c2) :
	_c1(c1),
	_c2(c2) {
	
}

ComparateurLexicographique::ComparateurLexicographique(const ComparateurLexicographique & other) : 
	_c1(other._c1),
	_c2(other._c2) {
	
}

string ComparateurLexicographique::toString() const {
	return "Lexicographique (" + _c1->toString() + ", " + _c2->toString() + ")";
}

int ComparateurLexicographique::compare(const Figure *f1, const Figure *f2) const {
	int comp1 = _c1->compare(f1, f2);
	if (comp1 != 0) {
		return comp1;
	}
	return _c2->compare(f1, f2);
}

ComparateurLexicographique &ComparateurLexicographique::operator=(const ComparateurLexicographique &other) {
	_c1 = other._c1;
	_c2 = other._c2;
	return *this;
}

}
