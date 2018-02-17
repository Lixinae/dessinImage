#ifndef CERCLE_H
#define CERCLE_H

#include "figure.hpp"

namespace figure {

using namespace std;

class Cercle : public Figure {
public:
    static Cercle temoin;

    explicit Cercle(const Point &centre = Point(0, 0), int rayon = 0)
            : _centre(centre), _rayon(rayon) {}

    std::shared_ptr<Figure> copy() const override;

    ~Cercle() override = default;

    void deplacer(const Point &trans) override;

    void dessiner(ostream &os = cout) const override;

    double surface() const override;

    void afficher(ostream &os = cout) const override;

private:
    Point _centre;
    int _rayon;
};

}

#endif
