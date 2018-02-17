#ifndef ESTUN_H
#define ESTUN_H

#include <cstring>
#include <typeinfo>
#include "condition.hpp"

namespace condition {

    class EstUn : public Condition {

    public:

        /**
         * Construit une condition d'egalite
         * \param f : figure pour tester l'egalite
         */
        explicit EstUn(const Figure *f);

        /**
           * Constructeur de copie
           * Les pointeurs sur la figure sont partages
           * \param other : condition a copier
           */
        explicit EstUn(const EstUn &other);

        /**
         * Renvoie la condition sous forme de chaine de caractere
         * \return la condition sous forme de chaine de caractere
         */
        string toString() const override;

        /**
         * Verifie si la figure est la meme
         * \param f : figure a tester
         * \return true si la figure est la meme, false sinon
         */
        bool verif(const Figure *f) const override;

        /**
         * Operateur d'affection
         * Les pointeurs sur la figure sont partages
         * \param other : condition a affecter
         * \return l'instance courante
         */
        EstUn &operator=(const EstUn &other);

    private :

        const Figure *ftemoin;

    };

}

#endif
