#include "point.hpp"

namespace figure {

Point::Point(int x, int y) : _x(x), _y(y) {
	
}

Point::Point() : Point(0,0) {
	
};

int Point::Point::getX() const {
    return _x;
}

int Point::Point::getY() const {
    return _y;
}


Point Point::operator+(const Point &p) const { //TODO rm
    return Point(_x + p._x, _y + p._y);
}

Point &Point::operator+=(const Point &p) {//TODO rm
    _x += p._x;
    _y += p._y;
    return *this;
}

ostream &operator<<(ostream &os, const Point &p) {
    return (os << '(' << p._x << ',' << p._y << ')');
}

}
