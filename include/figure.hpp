
#ifndef FIGUREH
#define FIGUREH

#include <iostream>
#include "point.hpp"
#include <memory>

namespace figure {

using namespace std;

class Figure {

public:

   /**
	* Realise une copie profonde de la figure
	* \return une copie profonde de la figure
	*/ 
    virtual std::shared_ptr<Figure> copy() const = 0; // TODO figure *

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
    * Dessine la figure
    * \param os : flux
    */
    virtual void dessiner(ostream &os = cout) const = 0; //TODO rm os

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
