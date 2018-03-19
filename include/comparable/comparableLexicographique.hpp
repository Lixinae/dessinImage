#ifndef COMPARABLELEXICO_H
#define COMPARABLELEXICO_H

#include "comparable/comparable.hpp"

namespace comparable {

    class ComparableLexicographique : public Comparable {

    public:

		/**
		 * Creer un composite de comparable selon l'ordre lexicographique
		 * \param p : Point de comparaison pour le comparable
		 */
		ComparableLexicographique(Comparable * c1, Comparable * c2);

		/**
          * Constructeur de copie
          * Les pointeurs sur les comparables sont partages
          * \param other : comparable a copier
          */
		ComparableLexicographique(const ComparableLexicographique & other);

        /**
         * Compare deux figures selon l'ordre lexicographique des comparables qui le compose
         * \param f2 : premiere figure a comparer 
         * \param f2 : deuxieme figure a comparer 
         * \return un entier positif si la premiere figure est superieur a la deuxieme,
         * 		   un entier negatif si la deuxieme figure est superieur a la premiere,
         * 		   0 sinon
         */
        int compare(const Figure *f1, const Figure *f2) const override;

        /**
         * Renvoie le comparable sous forme de chaine de caractere
         * \return le comparable sous forme de chaine de caractere
         */
        virtual string toString() const override;
        
        /**
         * Operateur d'affection
         * Les pointeurs sur les comparables sont partages
         * \param other : comparable a affecter
         * \return l'instance courante
         */
        ComparableLexicographique & operator=(const ComparableLexicographique &other);

	private:
	
		Comparable * _c1;
		Comparable * _c2;

    };

}

#endif
