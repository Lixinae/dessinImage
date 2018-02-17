#ifndef ESTPETITE_H
#define ESTPETITE_H

#include "condition.hpp"

/**
 * Conversion d'un entier en un objet string
 */
extern string intToString(int n);

class EstPetite : public Condition {

public:
    explicit EstPetite(double seuil) : _seuil(seuil) {
    }

    ~EstPetite() override = default;

//    double getSeuil() const {
//        return _seuil;
//    }

    string toString() const override {
        return string("La surface EST PLUS PETITE QUE ") + "" + intToString(static_cast<int>(_seuil));
    }

    bool verif(const Figure *f) const override {
        return f->surface() < this->_seuil;
    }

private:
    double _seuil;
};

#endif
