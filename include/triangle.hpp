//
// Created by ValasNaerth on 17/02/2018.
//

#ifndef DESSINIMAGE_TRIANGLE_HPP
#define DESSINIMAGE_TRIANGLE_HPP

#include "figure.hpp"

class Triangle : public Figure {
public:
    static Triangle temoin;

    explicit Triangle(const Point &point1 = Point(0, 1), const Point &point2 = Point(-1, 0),
                      const Point &point3 = Point(0, 1))
            : _point1(point1), _point2(point2), _point3(point3) {}

    std::shared_ptr<Figure> copy() const override;

    ~Triangle() override = default;

    void deplacer(const Point &trans) override;

    void dessiner(ostream &os = cout) const override;

    double surface() const override;

    double perimetre() const override;

    void afficher(ostream &os = cout) const override;

private:
    Point _point1;
    Point _point2;
    Point _point3;
}
#endif //DESSINIMAGE_TRIANGLE_HPP
