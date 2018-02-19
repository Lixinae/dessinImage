//
// Created by ValasNaerth on 17/02/2018.
//

#include <triangle.hpp>

namespace figure {

    Triangle::Triangle() : _point1(0, 1), _point2(-1, 0), _point3(0, 1) {

    }

    Triangle::Triangle(const Point &point1, const Point &point2, const Point &point3) : _point1(point1),
                                                                                        _point2(point2),
                                                                                        _point3(point3) {}

	string Triangle::nom() const {
		return "triangle";
	}

    void Triangle::deplacer(const Point &trans) {

    }

    double Triangle::surface() const {
        auto a = sqrt(pow(_point1.getX() - _point2.getX(), 2)
                      + pow(_point1.getY() - _point2.getY(), 2));
        auto b = sqrt(pow(_point2.getX() - _point3.getX(), 2)
                      + pow(_point2.getY() - _point3.getY(), 2));
        auto c = sqrt(pow(_point1.getX() - _point3.getX(), 2)
                      + pow(_point1.getY() - _point3.getY(), 2));
        auto s = (1 / 2) * (a + b + c);
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double Triangle::perimetre() const {
        auto distance1 = sqrt(pow(_point1.getX() - _point2.getX(), 2)
                              + pow(_point1.getY() - _point2.getY(), 2));
        auto distance2 = sqrt(pow(_point2.getX() - _point3.getX(), 2)
                              + pow(_point2.getY() - _point3.getY(), 2));
        auto distance3 = sqrt(pow(_point1.getX() - _point3.getX(), 2)
                              + pow(_point1.getY() - _point3.getY(), 2));
        return distance1 + distance2 + distance3;
    }

    void Triangle::afficher(ostream &os) const {
        os << "triangle : (" << _point1 << ", " << _point2 << ", " << _point3 << ")" << endl;
    }

    shared_ptr<Figure> Triangle::copy() const {
        return std::make_shared<Triangle>(this->_point1, this->_point2, this->_point3);
    }

    void Triangle::dessiner(const Dessin &dessin) const {
        dessin.dessinePolygone(vector<Point>{_point1, _point2, _point3});
    }

    void Triangle::homothetie(float k) {
        // todo
    }

    void Triangle::rotation(float theta) {
        // todo
    }

    void Triangle::translation(int x, int y) {
        // todo
    }

    const Point &Triangle::get_point1() const {
        return _point1;
    }

    const Point &Triangle::get_point2() const {
        return _point2;
    }

    const Point &Triangle::get_point3() const {
        return _point3;
    }


}
