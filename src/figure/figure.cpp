#include "figure/figure.hpp"

namespace figure {
	bool Figure::operator==(const Figure &f) const {
		return (this == &f); //TODO egalite memoire ?
	}

	ostream &operator<<(ostream &os, const Figure &figure) {
		figure.afficher(os);
		return os;
	}
}
