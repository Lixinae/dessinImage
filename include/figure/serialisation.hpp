#ifndef SERIALISATION_H
#define SERIALISATION_H

#include "figure/figure.hpp"
#include <list> 

namespace figure {

using namespace std;

class Serialisation {

public:

   /**
    * Sauvegarde la figure dans un fichier
    * \param fichier : nom du fichier
    * \param figure : figure a sauvegarder
    */
	virtual void sauvegarde(const string &fichier, const Figure &figure) const = 0;
	
   /**
    * Sauvegarde le vecteur de figures dans un fichier
    * \param fichier : nom du fichier
    * \param figure : conteneur figure a sauvegarder
    */
	virtual void sauvegarde_conteneur(const string &fichier, const list<shared_ptr<Figure>> &figures) const = 0;

   /**
    * Charge une figure depuis un fichier
    * \param fichier : nom du fichier
    * \return la figure stockee dans le fichier
    */
	virtual shared_ptr<Figure> charge(const string &fichier) const = 0;
	
   /**
    * Charge un vecteur de figures depuis un fichier
    * \param fichier : nom du fichier
    * \return la figure stockee dans le fichier
    */
	virtual list<shared_ptr<Figure>> charge_conteneur(const string &fichier) const = 0;
	
   /**
    * Detruit la classe de serialisation
    */
   virtual ~Serialisation() = default;

};

}

#endif
