#include <figure/rectangle.hpp>

namespace figure {


    Rectangle Rectangle::temoin = Rectangle();

    Rectangle::Rectangle() : Rectangle(Point(0, 0), Point(1, 1)) {

    }

    Rectangle::Rectangle(const Point &upperLeft, const Point &lowerRight) :
		_upperLeft(upperLeft), 
		_lowerRight(lowerRight) {

    }

    std::shared_ptr<Figure> Rectangle::copy() const {
        return std::make_shared<Rectangle>(_upperLeft, _lowerRight);
    }

    std::string Rectangle::nom() const {
        return "rectangle";
    }

    void Rectangle::tranformation(const Matrice2D & matrice) {
		_upperLeft = matrice * _upperLeft; 
		_lowerRight = matrice * _lowerRight; 
	}

    void Rectangle::dessiner(const Dessin &dessin) const {
		dessin.dessinePolygone(
			{_upperLeft.getX(), _upperLeft.getX(), _lowerRight.getX(), _lowerRight.getX()},
			{_upperLeft.getY(), _lowerRight.getY(), _lowerRight.getY(), _upperLeft.getY()}
		);
    }
    
    Point Rectangle::origine() const {
        auto x = (_upperLeft.getX() + _lowerRight.getX())/2.f;
        auto y = (_upperLeft.getY() + _lowerRight.getY())/2.f;
		return Point(x,y);
	}

    double Rectangle::surface() const {
		float h = abs(_upperLeft.getY() - _lowerRight.getY());
		float w = abs(_upperLeft.getX() - _lowerRight.getX());
        return (h*w);
    }

    double Rectangle::perimetre() const {
        float h = abs(_upperLeft.getY() - _lowerRight.getY());
		float w = abs(_upperLeft.getX() - _lowerRight.getX());
        return 2*(h+w);
    }

    void Rectangle::afficher(std::ostream &os) const {
        os << "rectangle : (" << _upperLeft << ", " << _lowerRight << ")" << endl;
    }

    const Point &Rectangle::get_upperLeft() const {
        return _upperLeft;
    }
    
    const Point &Rectangle::get_lowerRight() const {
        return _lowerRight;
    }

}

