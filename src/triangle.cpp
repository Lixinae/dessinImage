//
// Created by ValasNaerth on 17/02/2018.
//

#include <triangle.hpp>
#include <cmath>

namespace figure {
    Triangle::Triangle(const Point &point1, const Point &point2, const Point &point3) : _point1(point1),
                                                                                        _point2(point2),
                                                                                        _point3(point3) {}

    void Triangle::deplacer(const Point &trans) {

    }

    void Triangle::dessiner(ostream &os) const {
        os << *this << endl;;
    }

    double Triangle::surface() const {
        // TODo
        // base * hauteur / 2
        return 0;
    }

    double Triangle::perimetre() const {
        double distance1 = sqrt(pow(_point1.getX() - _point2.getX(), 2)
                                + pow(_point1.getY() - _point2.getY(), 2));
        double distance2 = sqrt(pow(_point2.getX() - _point3.getX(), 2)
                                + pow(_point2.getY() - _point3.getY(), 2));
        double distance3 = sqrt(pow(_point1.getX() - _point3.getX(), 2)
                                + pow(_point1.getY() - _point3.getY(), 2));
        return distance1 + distance2 + distance3;
    }

    void Triangle::afficher(ostream &os) const {
        os << "triangle : (" << _point1 << ", " << _point2 << ", " << _point3 << ")" << endl;
    }

    shared_ptr<Figure> Triangle::copy() const {
        return std::make_shared<Triangle>(this->_point1, this->_point2, this->_point3);
    }
}
