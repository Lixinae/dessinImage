#ifndef ESTPETITE_H
#define ESTPETITE_H

#include "condition.hpp"

namespace condition {

class EstPetite : public Condition {

public:


	/**
	 * Construit une condition de seuil pour l'aire
	 * \param seuil : seuil maximum pour l'aire
	 */
    explicit EstPetite(double seuil);

	/**
	 * Renvoie la condition sous forme de chaine de caractere
	 * \return la condition sous forme de chaine de caractere
	 */
    string toString() const override;

	/**
	 * Verifie si l'aire de la figure est plus petite que le seuil
	 * \param f : figure a tester
	 * \return true si l'aire de la figure est plus petit que le seuil, false sinon
	 */
   bool verif(const Figure *f) const override;

private:

    double _seuil;

};

}

#endif
