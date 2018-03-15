#ifndef CERCLE_H
#define CERCLE_H

#include <transformation/matrice2D.hpp>
#include "figure.hpp"

namespace figure {

    class Cercle : public Figure {

    public:

        static Cercle temoin;

        explicit Cercle();

        explicit Cercle(const Point &centre);

        explicit Cercle(const Point &center, int rayon);

        /**
         * Renvoie le centre du cercle
         * \return le centre du cercle
         */
        Point getCentre() const;

        /**
         * Renvoie le rayon du cercle
         * \return le rayon du cercle
         */
        int getRayon() const;

        /**
        * Realise une transformation decrite par une matrice sur le cercle
        * \param matrice : tranformation a appliquer
        */
        void tranformation(const Matrice2D &matrice);

        shared_ptr<Figure> copy() const override;

        /**
         * Renvoie le nom utilise pour identifier un cercle
         * \return le nom utilise pour identifier un cercle
         */
        string nom() const override;

        /**
         * Dessine le cercle dans la classe de dessin en argument
         * \param dessin : classe de dessin
         */
        void dessiner(const Dessin &dessin) const override;

        double surface() const override;

        double perimetre() const override;

        void afficher(ostream &os = cout) const override;

    private:

        Point _centre;
        int _rayon;

    };

}

#endif
