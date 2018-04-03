#ifndef COMPARATEURDISTANCE_H
#define COMPARATEURDISTANCE_H

#include "comparateur/comparateur.hpp"

namespace comparateur {

    class ComparateurDistance : public Comparateur {

    public:

		/**
		 * Creer un comparateur pour la distance entre un point et l'origine des figures
		 * \param p : Point de comparaison pour le comparable
		 */
		ComparateurDistance(const Point & p);

        /**
         * Compare deux figures selon leurs distance entre le point et leurs origine
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

	private:
	
		Point _p;

    };

}

#endif
