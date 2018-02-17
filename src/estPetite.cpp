//
// Created by ValasNaerth on 18/02/2018.
//
#include <estPetite.hpp>

EstPetite::EstPetite(double seuil) : _seuil(seuil) {

}

string EstPetite::toString() const {

    return string("La surface EST PLUS PETITE QUE ") + "" + intToString(static_cast<int>(_seuil));

}

bool EstPetite::verif(const Figure *f) const {
    return f->surface() < this->_seuil;
}
