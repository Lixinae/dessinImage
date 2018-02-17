#include "cercle.hpp"

namespace figure {

Cercle Cercle::temoin = Cercle(Point(0, 0), 0);

Cercle::Cercle() : Cercle(Point(0,0), 0) {

}
Cercle::Cercle(const Point &centre) : Cercle(centre, 0) {

}

Cercle::Cercle(const Point &centre, int rayon) : _centre(centre), _rayon(rayon) {

}

shared_ptr<Figure> Cercle::copy() const {
    return std::shared_ptr<Figure>(new Cercle(this->_centre, this->_rayon));
}

void Cercle::deplacer(const Point &p) {
    _centre += p;
}

void Cercle::dessiner(ostream &os) const {
    os << *this << endl;;
}

double Cercle::surface() const {
    return 3.1416 * _rayon * _rayon;
}

void Cercle::afficher(ostream &os) const {
    os << "cercle : (" << _centre << ", " << _rayon << ")" << endl;
}

}
