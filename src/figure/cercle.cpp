#include "figure/cercle.hpp"

namespace figure {

    Cercle Cercle::temoin = Cercle();

    Cercle::Cercle() : Cercle(Point(0, 0), 0) {

    }

    Cercle::Cercle(const Point &centre) : Cercle(centre, 0) {

    }

    Cercle::Cercle(const Point &centre, float rayon) : _centre(centre), _rayon(rayon) {

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
        Point temoin = _centre + Point(_rayon,0);
        _centre = matrice * _centre;
        temoin = matrice * temoin;
        float xx = _centre.getX() - temoin.getX();
        float yy = _centre.getY() - temoin.getY();
        _rayon = sqrt(xx*xx + yy*yy);
    }

    void Cercle::dessiner(const Dessin &dessin) const {
        dessin.dessineCercle(_centre.getX(), _centre.getY(), _rayon);
    }
   
	Point Cercle::origine() const {
		return _centre;
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
