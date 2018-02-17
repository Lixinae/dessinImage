#ifndef CONDITION_H
#define CONDITION_H

#include <list>
#include "figure/figure.hpp"

namespace condition {

    using namespace figure;

    class Condition {

    public:

        /**
         * Verifie la condition sur une figure
         * \param f : figure a tester
         * \return true si la condition est verifiee, false sinon
         */
        virtual bool verif(const Figure *f) const = 0;

        /**
         * Renvoie la condition sous forme de chaine de caractere
         * \return la condition sous forme de chaine de caractere
         */
        virtual string toString() const = 0;

        /**
         * Detruit la condition
         */
        virtual ~Condition() {};

    };

}

#endif
