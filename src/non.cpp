//
// Created by ValasNaerth on 18/02/2018.
//

#include <non.hpp>

Non::Non(const Non &other) : condition(other.condition) {

}

Non::Non(Condition *c) : condition(c) {

}

string Non::toString() const {
    return "NON " + condition->toString();
}

bool Non::verif(const Figure *f) const {
    return !(condition->verif(f));
}

Non &Non::operator=(const Non &other) {
    condition = other.condition;
    return *this;
}
