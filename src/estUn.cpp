//
// Created by ValasNaerth on 18/02/2018.
//

#include <estUn.hpp>

EstUn::EstUn(const EstUn &other) : ftemoin(other.ftemoin) {

}

string EstUn::toString() const {
    return "EST UN " + string(typeid(*ftemoin).name());
}

bool EstUn::verif(const Figure *f) const {
    return typeid(*ftemoin) == typeid(*f);
}

EstUn &EstUn::operator=(const EstUn &other) {
    ftemoin = other.ftemoin;
    return *this;
}
