/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr�ation : 2013-12-21
 * description      : impl�m�ntation d'une classe d�crivant un point
 */

#include "point.hpp"

Point::Point(int a, int b) : x(a), y(b) {
}

int Point::Point::getX() const {
    return x;
}

//void Point::Point::setX(int a) {
//    x = a;
//}
//
//void Point::Point::setY(int b) {
//    y = b;
//}

int Point::Point::getY() const {
    return x;
}


Point Point::operator+(const Point &p) const {
    return Point(x + p.x, y + p.y);
}

Point &Point::operator+=(const Point &p) {
    x += p.x;
    y += p.y;
    return *this;
}

Point &Point::operator=(const Point &p) {
    if (this == &p)
        return *this;

    x = p.x;
    y = p.y;

    return *this;
}

ostream &operator<<(ostream &os, const Point &p) {
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}

