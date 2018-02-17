#include <figure/rectangle.hpp>
#include <matrice2D.hpp>

figure::Rectangle::Rectangle() : _upperLeft(-1, 1), _upperRight(1, 1), _lowerLeft(-1, -1), _lowerRight(1, -1) {

}

figure::Rectangle::Rectangle(const figure::Point &upperLeft, const figure::Point &upperRight,
                             const figure::Point &lowerLeft, const figure::Point &lowerRight) :
        _upperLeft(upperLeft), _upperRight(upperRight), _lowerLeft(lowerLeft), _lowerRight(lowerRight) {

}

std::shared_ptr<figure::Figure> figure::Rectangle::copy() const {
    return std::shared_ptr<figure::Figure>();
}

std::string figure::Rectangle::nom() const {
    return "rectangle";
}

void figure::Rectangle::deplacer(const figure::Point &trans) {

}

void figure::Rectangle::translation(int x, int y) {
    Matrice2D transformation = Matrice2D::translation(x, y);
    _upperLeft = transformation * _upperLeft;
    _upperRight = transformation * _upperRight;
    _lowerLeft = transformation * _lowerLeft;
    _lowerRight = transformation * _lowerRight;
}

void figure::Rectangle::rotation(float theta) {
    Matrice2D transformation = Matrice2D::rotation(theta);
    _upperLeft = transformation * _upperLeft;
    _upperRight = transformation * _upperRight;
    _lowerLeft = transformation * _lowerLeft;
    _lowerRight = transformation * _lowerRight;
}

void figure::Rectangle::homothetie(float k) {
    Matrice2D transformation = Matrice2D::homothetie(k);
    _upperLeft = transformation * _upperLeft;
    _upperRight = transformation * _upperRight;
    _lowerLeft = transformation * _lowerLeft;
    _lowerRight = transformation * _lowerRight;
}

void figure::Rectangle::dessiner(const figure::Dessin &dessin) const {

}

double figure::Rectangle::surface() const {
    auto distance1 = sqrt(pow(_upperLeft.getX() - _upperRight.getX(), 2)
                          + pow(_upperLeft.getY() - _upperRight.getY(), 2));
    auto distance2 = sqrt(pow(_upperRight.getX() - _lowerRight.getX(), 2)
                          + pow(_upperRight.getY() - _lowerRight.getY(), 2));
    return distance1 * distance2;
}

double figure::Rectangle::perimetre() const {
    auto distance1 = sqrt(pow(_upperLeft.getX() - _upperRight.getX(), 2)
                          + pow(_upperLeft.getY() - _upperRight.getY(), 2));
    auto distance2 = sqrt(pow(_upperRight.getX() - _lowerRight.getX(), 2)
                          + pow(_upperRight.getY() - _lowerRight.getY(), 2));
    return (distance1 + distance2) * 2;
}

void figure::Rectangle::afficher(std::ostream &os) const {
    os << "rectangle : {"
       << " _upperLeft: " << _upperLeft << " _upperRight: " << _upperRight
       << " _lowerLeft: " << _lowerLeft << " _lowerRight: " << _lowerRight
       << "}";
}




