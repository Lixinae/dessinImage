#include "condition/estUn.hpp"

namespace condition {

EstUn::EstUn(const EstUn &other) : ftemoin(other.ftemoin) {}

EstUn::EstUn(const Figure *f) : ftemoin(f) {}

string EstUn::toString() const {
	return "EST UN " + string(ftemoin->nom()); 
}

bool EstUn::verif(const Figure *f) const {
	return (ftemoin->nom() == f->nom());
}

EstUn &EstUn::operator=(const EstUn &other) {
	ftemoin = other.ftemoin;
	return *this;
}

}
