#ifndef SERIALISATION_H
#define SERIALISATION_H

#include "figure.hpp"

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
    * Charge une figure depuis un fichier
    * \param fichier : nom du fichier
    * \return la figure stockee dans le fichier
    */
	virtual Figure * charge(const string &fichier) const = 0;
	
   /**
    * Detruit la classe de serialisation
    */
    virtual ~Serialisation() {};

};

}

#endif
