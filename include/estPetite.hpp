#ifndef ESTPETITE_H
#define ESTPETITE_H

#include "condition.hpp"

/**
 * Conversion d'un entier en un objet string
 */
extern string intToString(int n);

class EstPetite : public Condition {

public:
    explicit EstPetite(double seuil);

    ~EstPetite() override = default;

//    double getSeuil() const {
//        return _seuil;
//    }

    string toString() const override;

    bool verif(const Figure *f) const override;

private:
    double _seuil;
};

#endif
