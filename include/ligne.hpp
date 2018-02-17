
#ifndef LIGNE_H
#define LIGNE_H

#include "figure.hpp"

namespace figure {

class Ligne : public Figure {

public:

    static Ligne temoin;

    Ligne(const Point &a, const Point &b)
            : _origine(a), _extremite(b) {}

    std::shared_ptr<Figure> copy() const override;

    ~Ligne() override = default;

    void deplacer(const Point &trans) override;

    void dessiner(ostream &os = cout) const override;

    double surface() const override;

    void afficher(ostream &os = cout) const override;

private:
    Point _origine;
    Point _extremite;
};

}

#endif

