#ifndef COMPARABLE_H
#define COMPARABLE_H

#include "figure/figure.hpp"

namespace comparable {

    using namespace figure;

    class Comparable {

    public:

        /**
         * Compare deux figures
         * \param f2 : premiere figure a comparer 
         * \param f2 : deuxieme figure a comparer 
         * \return un entier positif si la premiere figure est superieur a la deuxieme,
         * 		   un entier negatif si la deuxieme figure est superieur a la premiere,
         * 		   0 sinon
         */
        virtual int compare(const Figure *f1, const Figure *f2) const = 0;

        /**
         * Renvoie le comparable sous forme de chaine de caractere
         * \return le comparable sous forme de chaine de caractere
         */
        virtual string toString() const = 0;

        /**
         * Detruit le comparable
         */
        virtual ~Comparable() {};
        
        /**
         * Ecrit un co dans un flux
         * \param os : le flux
         * \param figure : la condition a ecrire
         * \return le flux
         */
        friend ostream &operator<<(ostream &os, const Comparable &comparable);

    };

}

#endif
