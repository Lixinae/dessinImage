#include "ligne.hpp"

#include <cmath>
#include "matrice2D.hpp"

namespace figure {

    Ligne Ligne::temoin = Ligne(Point(0, 0), Point(1, 1));

    Ligne::Ligne(const Point &a, const Point &b) : _origine(a), _extremite(b) {

    }

    std::shared_ptr<Figure> Ligne::copy() const {
        return std::make_shared<Ligne>(this->_origine, this->_extremite);
    }

	void Ligne::translation(int x, int y) {
		Matrice2D transformation = Matrice2D::translation(x,y);
		_origine = transformation * _origine;
		_extremite = transformation * _extremite;
	}

	void Ligne::rotation(float theta) {
		Matrice2D transformation = Matrice2D::rotation(theta);
		_origine = transformation * _origine;
		_extremite = transformation * _extremite;
	}
		
	void Ligne::homothetie(float /*k*/) { //TODO homothetie sur ligne ?
		//TODO
	}
	
    void Ligne::deplacer(const Point &p) {
        _origine += p;
        _extremite += p;
    }

    void Ligne::dessiner(const Dessin &dessin) const {
        dessin.dessineLigne(_origine, _extremite);
    }

    double Ligne::surface() const {
        double xx = _origine.getX() - _extremite.getX();
        double yy = _origine.getY() - _extremite.getY();
        double distance = sqrt(pow(xx, 2) + pow(yy, 2));
        return distance;
    }

    double Ligne::perimetre() const {
        double xx = _origine.getX() - _extremite.getX();
        double yy = _origine.getY() - _extremite.getY();
        double distance = sqrt(pow(xx, 2) + pow(yy, 2));
        double epaisseur = 1.0;
        return 2 * distance + 2 * epaisseur;
    }

    void Ligne::afficher(ostream &os) const {
        os << "ligne (" << _origine << ", " << _extremite << ")" << endl;
    }


}
