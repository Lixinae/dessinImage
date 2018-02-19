#ifndef ET_H
#define ET_H

#include "condition.hpp"

namespace condition {

class Et : public Condition {

public:
	
	/**
	 * Construit une conjonction de condition
	 * \param c1 : premiere condition
	 * \param c2 : deuxieme condition
	 */
    explicit Et(Condition *c1, Condition *c2);
    
    /**
	 * Constructeur de copie
	 * Les pointeurs sur les conditions sont partages
	 * \param other : condition a copier
	 */
	explicit Et(const Et &other);
    
    /**
	 * Renvoie la condition sous forme de chaine de caractere
	 * \return la condition sous forme de chaine de caractere
	 */
    string toString() const override ;
    
    /**
	 * Verifie si les deux conditions sont verifiees
	 * \param f : figure a tester
	 * \return true si les deux conditions sont verifiees, false sinon
	 */
    bool verif(const Figure *f) const override;

	/**
     * Operateur d'affection
     * Les pointeurs sur les conditions sont partages
     * \param other : condition a affecter
     * \return l'instance courante
     */
    Et &operator=(const Et &other);

private:

    Condition *_c1;
    Condition *_c2;

};

}

#endif
