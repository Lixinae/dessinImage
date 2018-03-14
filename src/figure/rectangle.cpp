#include <figure/rectangle.hpp>
#include <matrice2D.hpp>

namespace figure {


    Rectangle Rectangle::temoin = Rectangle();

    Rectangle::Rectangle() : _upperLeft(-1, 1), _upperRight(1, 1), _lowerLeft(-1, -1), _lowerRight(1, -1) {

    }

    Rectangle::Rectangle(const Point &upperLeft, const Point &upperRight,
                         const Point &lowerLeft, const Point &lowerRight) :
            _upperLeft(upperLeft), _upperRight(upperRight), _lowerLeft(lowerLeft), _lowerRight(lowerRight) {

    }

    std::shared_ptr<Figure> Rectangle::copy() const {
        return std::shared_ptr<Figure>();
    }

    std::string Rectangle::nom() const {
        return "rectangle";
    }

    void Rectangle::deplacer(const Point &trans) {

    }
    
    void Rectangle::tranformation(const Matrice2D & matrice) {
		//TODO
	}

    void Rectangle::translation(int x, int y) {
        Matrice2D transformation = Matrice2D::translation(x, y);
        _upperLeft = transformation * _upperLeft;
        _upperRight = transformation * _upperRight;
        _lowerLeft = transformation * _lowerLeft;
        _lowerRight = transformation * _lowerRight;
    }

    void Rectangle::rotation(float theta) {
        Matrice2D transformation = Matrice2D::rotation(theta);
        _upperLeft = transformation * _upperLeft;
        _upperRight = transformation * _upperRight;
        _lowerLeft = transformation * _lowerLeft;
        _lowerRight = transformation * _lowerRight;
    }

    void Rectangle::homothetie(float k) {
        Matrice2D transformation = Matrice2D::homothetie(k);
        _upperLeft = transformation * _upperLeft;
        _upperRight = transformation * _upperRight;
        _lowerLeft = transformation * _lowerLeft;
        _lowerRight = transformation * _lowerRight;
    }

    void Rectangle::dessiner(const Dessin &dessin) const {
        dessin.dessinePolygone(vector<Point>{_upperLeft, _upperRight, _lowerLeft, _lowerRight});
    }

    double Rectangle::surface() const {
        auto distance1 = sqrt(pow(_upperLeft.getX() - _upperRight.getX(), 2)
                              + pow(_upperLeft.getY() - _upperRight.getY(), 2));
        auto distance2 = sqrt(pow(_upperRight.getX() - _lowerRight.getX(), 2)
                              + pow(_upperRight.getY() - _lowerRight.getY(), 2));
        return distance1 * distance2;
    }

    double Rectangle::perimetre() const {
        auto distance1 = sqrt(pow(_upperLeft.getX() - _upperRight.getX(), 2)
                              + pow(_upperLeft.getY() - _upperRight.getY(), 2));
        auto distance2 = sqrt(pow(_upperRight.getX() - _lowerRight.getX(), 2)
                              + pow(_upperRight.getY() - _lowerRight.getY(), 2));
        return (distance1 + distance2) * 2;
    }

    void Rectangle::afficher(std::ostream &os) const {
        os << "rectangle : {"
           << " _upperLeft: " << _upperLeft << " _upperRight: " << _upperRight
           << " _lowerLeft: " << _lowerLeft << " _lowerRight: " << _lowerRight
           << "}";
    }

    const Point &Rectangle::get_upperLeft() const {
        return _upperLeft;
    }

    const Point &Rectangle::get_upperRight() const {
        return _upperRight;
    }

    const Point &Rectangle::get_lowerLeft() const {
        return _lowerLeft;
    }

    const Point &Rectangle::get_lowerRight() const {
        return _lowerRight;
    }


}

