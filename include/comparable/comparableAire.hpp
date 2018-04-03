#ifndef COMPARATEURAIRE_H
#define COMPARATEURAIRE_H

#include "comparable/comparable.hpp"

namespace comparable {

    class ComparateurAire : public Comparateur {

    public:

        /**
         * Compare deux figures selon leurs aires
         * \param f2 : premiere figure a comparer 
         * \param f2 : deuxieme figure a comparer 
         * \return un entier positif si la premiere figure est superieur a la deuxieme,
         * 		   un entier negatif si la deuxieme figure est superieur a la premiere,
         * 		   0 sinon
         */
        int compare(const Figure *f1, const Figure *f2) const override;

        /**
         * Renvoie le comparateur sous forme de chaine de caractere
         * \return le comparateur sous forme de chaine de caractere
         */
        virtual string toString() const override;


    };

}

#endif
