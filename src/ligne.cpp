/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr�ation : 2013-12-21
 * description      : impl�m�ntation d'une classe d�crivant une ligne dans une hi�rachie de figures
 */

#include "ligne.hpp"
#include <cmath>

namespace figure {


/**
 * La ligne t�moin est une variable de classe
 */
Ligne Ligne::temoin = Ligne(Point(0, 0), Point(1, 1));

/**
 * Fonction virtuelle de copie
 */
std::shared_ptr<Figure> Ligne::copy() const {
    return std::shared_ptr<Figure>(new Ligne(this->_origine, this->_extremite));
}

/**
 * D�placement-translation de valeur le point p
 */
void Ligne::deplacer(const Point &p) {
    _origine += p;
    _extremite += p;
}

/**
 * Le dessin se limite � un affichage
 */
void Ligne::dessiner(ostream &os) const {
    os << *this << endl;;
}

/**
 * TOUR DE MAGIE GEOMETRIQUE
 * une ligne est vue pour les besoins de la cause comme
 * une segment (origine, exptremite] avec une �paisseur
 * soit un rectangle dont on peut calculer la surfade!!!!
 */
double Ligne::surface() const {
    double distance = sqrt((_origine.getX() - _extremite.getX()) * (_origine.getX() - _extremite.getX())
                           + (_origine.getY() - _extremite.getY()) * (_origine.getY() - _extremite.getY()));

    const double epaisseur = 1.0;

    return distance * epaisseur;
}

void Ligne::afficher(ostream &os) const {
    os << "ligne (" << _origine << ", " << _extremite << ")" << endl;
}

}
