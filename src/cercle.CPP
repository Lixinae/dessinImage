/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr?ation : 2013-12-21
 * description      : impl?m?ntation d'une classe d?crivant un cercle dans une hi?rachie de figures
 */

#include "cercle.hpp"

/**
 * Le cercle t?moin est une variable de classe
 */
Cercle Cercle::temoin = Cercle(Point(0, 0), 0);


/**
 * Fonction virtuelle de copie
 */
shared_ptr<Figure> Cercle::copy() const {
    return std::shared_ptr<Figure>(new Cercle(this->_centre, this->_rayon));
}

/**
 * D?placement-translation de valeur le point p
 */
void Cercle::deplacer(const Point &p) {
    _centre += p;
}

/**
 * Le dessin se limite ? un affichage
 */
void Cercle::dessiner(ostream &os) const {
    os << *this << endl;;
}

double Cercle::surface() const {
    return PI * _rayon * _rayon;
}

void Cercle::afficher(ostream &os) const {
    os << "cercle : (" << _centre << ", " << _rayon << ")" << endl;
}

double Cercle::perimetre() const {
    return 2 * PI * _rayon;
}

