#ifndef NON_H
#define NON_H

#include "condition.hpp"

namespace condition {

class Non : public Condition {

public:

	/**
	 * Construit une negation de condition
	 * \param c : condition
	 */
    explicit Non(Condition *c);
    
    /**
	 * Constructeur de copie
	 * Les pointeurs sur la condition sont partages
	 * \param other : condition a copier
	 */
    explicit Non(const Non &other);

	/**
	 * Renvoie la condition sous forme de chaine de caractere
	 * \return la condition sous forme de chaine de caractere
	 */
    string toString() const override;
    
    /**
	 * Verifie si la negation de la condition est verifiee
	 * \param f : figure a tester
	 * \return true si la negation de la condition est verifiee, false sinon
	 */
    bool verif(const Figure *f) const override;

	 /**
     * Operateur d'affection
     * Les pointeurs sur la sont partages
     * \param other : condition a affecter
     * \return l'instance courante
     */
    Non &operator=(const Non &other);

private:

    Condition *condition;

};

}

#endif
