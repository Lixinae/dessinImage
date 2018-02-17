#include "cercle.hpp"
#include "matrice2D.hpp"

namespace figure {

    Cercle Cercle::temoin = Cercle(Point(0, 0), 0);

    Cercle::Cercle() : Cercle(Point(0, 0), 0) {

    }

    Cercle::Cercle(const Point &centre) : Cercle(centre, 0) {

    }

    Cercle::Cercle(const Point &centre, int rayon) : _centre(centre), _rayon(rayon) {

    }

    shared_ptr<Figure> Cercle::copy() const {
        return std::make_shared<Cercle>(this->_centre, this->_rayon);
    }

	void Cercle::translation(int x, int y) {
		Matrice2D transformation = Matrice2D::translation(x,y);
		_centre = transformation * _centre;
	}

	void Cercle::rotation(float theta) { //TODO rotation d'un cercle ?
	
	}
	
	void Cercle::homothetie(float k) {
		Matrice2D transformation = Matrice2D::homothetie(k);
		_centre = transformation * _centre;
		_rayon *= k;
	}

	void Cercle::dessiner(const Dessin &dessin) const {
		dessin.dessineCercle(_centre, _rayon);
	}
    
    void Cercle::deplacer(const Point &p) {
        _centre += p;
    }

    double Cercle::surface() const {
       // return PI * pow(_rayon,2);
       return 3.1415 * pow(_rayon,2);
    }

    double Cercle::perimetre() const {
        //return 2*PI*_rayon;
        return 2*3.1415*_rayon;
    }

    void Cercle::afficher(ostream &os) const {
        os << "cercle : (" << _centre << ", " << _rayon << ")" << endl;
    }


}
