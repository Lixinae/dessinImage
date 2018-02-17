//
// Created by ValasNaerth on 17/02/2018.
//

#include <triangle.hpp>

void Triangle::deplacer(const Point &trans) {

}

void Triangle::dessiner(ostream &os) const {
    os << *this << endl;;
}

double Triangle::surface() const {
    // TODo
    return 0;
}

double Triangle::perimetre() const {
    double distance1 = sqrt(pow(_point1.getX() - _point2.getX(),2)
                           + pow(_point1.getY() - _point2.getY(),2));
    double distance2 = sqrt(pow(_point2.getX() - _point3.getX(),2)
                           + pow(_point2.getY() - _point3.getY(),2));
    double distance3 = sqrt(pow(_point1.getX() - _point3.getX(),2)
                           + pow(_point1.getY() - _point3.getY(),2));
    return distance1+distance2+distance3;
}

void Triangle::afficher(ostream &os) const {
    os << "triangle : (" << _point1 << ", " << _point2 << ", " <<_point3 << ")" << endl;
}
