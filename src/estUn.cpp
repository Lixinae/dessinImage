#include "estUn.hpp"

namespace condition {

EstUn::EstUn(const EstUn &other) : ftemoin(other.ftemoin) {}

EstUn::EstUn(const Figure *f) : ftemoin(f) {}

string EstUn::toString() const {
	return "EST UN " + string(typeid(*ftemoin).name()); 
}

bool EstUn::verif(const Figure *f) const {
	return typeid(*ftemoin) == typeid(*f); //TODO typeid pas de polymorphisme => utiliser f->nom()
}

EstUn &EstUn::operator=(const EstUn &other) {
	ftemoin = other.ftemoin;
	return *this;
}