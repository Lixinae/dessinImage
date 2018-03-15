#include "figure/cercle.hpp"

namespace figure {

    Cercle Cercle::temoin = Cercle(Point(0, 0), 0);

    Cercle::Cercle() : Cercle(Point(0, 0), 0) {

    }

    Cercle::Cercle(const Point &centre) : Cercle(centre, 0) {

    }

    Cercle::Cercle(const Point &centre, int rayon) : _centre(centre), _rayon(rayon) {

    }

    Point Cercle::getCentre() const {
        return _centre;
    }

    int Cercle::getRayon() const {
        return _rayon;
    }

    shared_ptr<Figure> Cercle::copy() const {
        return std::make_shared<Cercle>(this->_centre, this->_rayon);
    }

    std::string Cercle::nom() const {
        return "cercle";
    }

    void Cercle::tranformation(const Matrice2D &matrice) {
        //TODO
    }

    void Cercle::dessiner(const Dessin &dessin) const {
        dessin.dessineCercle(_centre.getX(), _centre.getY(), _rayon);
    }

    double Cercle::surface() const {
        return PI * _rayon * _rayon;
    }

    double Cercle::perimetre() const {
        return 2 * PI * _rayon;
    }

    void Cercle::afficher(ostream &os) const {
        os << "cercle : (" << _centre << ", " << _rayon << ")" << endl;
    }


}
