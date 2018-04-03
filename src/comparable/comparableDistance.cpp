#include "comparable/comparableDistance.hpp"

#include <string>

namespace comparable {

ComparateurDistance::ComparateurDistance(const Point & p) : _p(p) {
	
}

string ComparateurDistance::toString() const {
	return "Distance a (" + to_string(_p.getX()) + ", " + to_string(_p.getY()) + ")";
}

int ComparateurDistance::compare(const Figure *f1, const Figure *f2) const {
	Point origine1 = f1->origine();
	Point origine2 = f2->origine();
	float x1 = origine1.getX() - _p.getX();
	float y1 = origine1.getY() - _p.getY();
	float x2 = origine2.getX() - _p.getX();
	float y2 = origine2.getY() - _p.getY();
	float d1 = sqrt(x1*x1 + y1*y1);
	float d2 = sqrt(x2*x2 + y2*y2);
	if (d1 < d2) {
		return -1;
	}
	if (d1 > d2) {
		return 1;
	}
	return 0;
}

}
