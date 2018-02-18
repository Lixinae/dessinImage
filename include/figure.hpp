
#ifndef FIGUREH
#define FIGUREH

#include <iostream>
#include "point.hpp"
#include <memory>
#include <cmath>
#include "dessin.hpp"

namespace figure {

using namespace std;

class Figure {

public:

   /**
	* Realise une copie profonde de la figure
	* \return une copie profonde de la figure
	*/ 
    virtual shared_ptr<Figure> copy() const = 0;

	/**
	 * Renvoie le nom de la figure
	 * \return le nom de la figure
	 */
	virtual string nom() const = 0;

   /**
    * Detruit la figure
    */
    virtual ~Figure() {};

   /**
    * Deplace la figure
    * \param trans : translation
    */
    virtual void deplacer(const Point &trans) = 0; // TODO operation(matrice2d)

    /**
	 * Realise une translation sur la figure
	 * \param x : valeur de la translation en abscisse
	 * \param y : valeur de la translation en ordonnnee
	 */
	virtual void translation(int x, int y) = 0;
	
    /**
	 * Realise une rotation sur la figure
	 * \param thetat : valeur de l'angle de rotation en radian
	 */
	virtual void rotation(float theta) = 0;
	
    /**
	 * Realise une homothetie sur la figure
	 * \param k : valeur de l'homothetie
	 */
	virtual void homothetie(float k) = 0;

   /**
    * Dessine la figure dans la classe de dessin en argument
    * \param dessin : classe de dessin
    */
    virtual void dessiner(const Dessin &dessin) const = 0;

   /**
    * Affiche la figure dans un flux
    * \param os : le flux
    * \return le flux
    */
    virtual void afficher(ostream &os) const = 0;
    
   /**
    * Calcule la surface de la figure
    * \return la surface de la figure
    */
    virtual double surface() const = 0; //TODO rm -> perimetre aire
    
   /**
	* Calcule le perimetre de la figure
	* \return le perimetre de la figure
	*/
	virtual double perimetre() const = 0; //TODO rm -> perimetre aire

   /**
    * Teste l'egalite de deux figures
    * \param f : figure a tester
    * \return true si les figures sont les memes, faux sinon
    */
    bool operator==(const Figure &f) const {
        return (this == &f); //TODO egalite memoire ?
    }

   /**
    * Ecrit une figure dans un flux
    * \param os : le flux
    * \param figure : la figure a ecrire
    * \return le flux
    */
    friend ostream &operator<<(ostream &os, const Figure &figure) {
        figure.afficher(os);
        return os;
    }

};
}

#endif
