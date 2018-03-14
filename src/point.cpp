#include "point.hpp"

namespace figure {

    Point::Point(float x, float y) : _x(x), _y(y) {}

    Point::Point() : Point(0, 0) {};

    float Point::Point::getX() const {
        return _x;
    }

    float Point::Point::getY() const {
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
