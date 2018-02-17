
#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include "figure.hpp"
#include <set>
#include <numeric>

namespace figure {

    class Image : public Figure {

    public:

        static Image temoin;

        //TODO
        /*explicit*/ Image();

        /*explicit*/ Image(const Point &p);

        /*explicit*/ Image(const Image &image);

        std::shared_ptr<Figure> copy() const override;

        const shared_ptr<Figure> getFigure(int index) const;

        int getNombre() const;

        Point getOrigine() const;

        void ajouter(const Figure &f);

        void deplacer(const Point &trans) override;

        void dessiner(ostream &os = cout) const override;

        double surface() const override;

        double perimetre() const override;

        void afficher(ostream &os = cout) const override;

    private:

        Point _origine;

        set<std::shared_ptr<Figure>> _figures;

        static void afficherAux(ostream &os, const Image &image, int niveau);

    };

}

#endif
