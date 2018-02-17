
#ifndef DESSIN_H
#define DESSIN_H

#include "point.hpp"
#include <vector>

namespace figure {

    using namespace std;

    class Dessin {

    public:

        /**
         * Initialise la classe de dessin
         */
        virtual void initialise() = 0;

        /**
         * Dessine une ligne
         * \param p1 : premiere point definissant la ligne
         * \param p2 : deuxieme point definissant la ligne
         */
        virtual void dessineLigne(const Point &p1, const Point &p2) const = 0;

        /**
         * Dessine un cercle
         * \param centre : centre du cercle
         * \param rayon : rayon du cercle
         */
        virtual void dessineCercle(const Point &centre, float rayon) const = 0;


        /**
         * Dessine un polygone
         * \param points : points definissant le contour du polygone
         */
        virtual void dessinePolygone(const vector<Point> &points) const = 0;

        /**
         * Met la fenetre en attente d'un evenement pour la maintenir ouverte
         */
        virtual void attendClick() const =0;

        /**
         * Detruit la classe de dessin
         */
        virtual ~Dessin() {};

    };

}

#endif
