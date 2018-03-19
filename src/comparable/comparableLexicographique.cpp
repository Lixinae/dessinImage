#include "comparable/comparableLexicographique.hpp"

namespace comparable {

ComparableLexicographique::ComparableLexicographique(Comparable * c1, Comparable * c2) :
	_c1(c1),
	_c2(c2) {
	
}

ComparableLexicographique::ComparableLexicographique(const ComparableLexicographique & other) : 
	_c1(other._c1),
	_c2(other._c2) {
	
}

string ComparableLexicographique::toString() const {
	return "Lexicographique (" + _c1->toString() + ", " + _c2->toString() + ")";
}

int ComparableLexicographique::compare(const Figure *f1, const Figure *f2) const {
	int comp1 = _c1->compare(f1, f2);
	if (comp1 != 0) {
		return comp1;
	}
	return _c2->compare(f1, f2);
}

ComparableLexicographique &ComparableLexicographique::operator=(const ComparableLexicographique &other) {
	_c1 = other._c1;
	_c2 = other._c2;
	return *this;
}

}
