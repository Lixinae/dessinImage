#ifndef COMPARATEURLEXICO_H
#define COMPARATEURLEXICO_H

#include "comparateur/comparateur.hpp"

namespace comparateur {

    class ComparateurLexicographique : public Comparateur {

    public:

		/**
		 * Creer un composite de comparateur selon l'ordre lexicographique
		 * \param p : Point de comparaison pour le comparable
		 */
		ComparateurLexicographique(Comparateur * c1, Comparateur * c2);

		/**
          * Constructeur de copie
          * Les pointeurs sur les comparateurs sont partages
          * \param other : comparateur a copier
          */
		ComparateurLexicographique(const ComparateurLexicographique & other);

        /**
         * Compare deux figures selon l'ordre lexicographique des comparateurs qui le compose
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
        
        /**
         * Operateur d'affection
         * Les pointeurs sur les comparateurs sont partages
         * \param other : comparateur a affecter
         * \return l'instance courante
         */
        ComparateurLexicographique & operator=(const ComparateurLexicographique &other);

	private:
	
		Comparateur * _c1;
		Comparateur * _c2;

    };

}

#endif
