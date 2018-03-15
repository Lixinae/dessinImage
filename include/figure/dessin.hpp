
#ifndef DESSIN_H
#define DESSIN_H

#include <vector>

namespace figure {

    using namespace std;

    class Dessin {

    public:

        /**
         * Dessine une ligne
         * \param x1 : valeur en abscisse du premier point definissant la ligne
         * \param y1 : valeur en ordonnee du premier point definissant la ligne
         * \param x2 : valeur en abscisse du deuxieme point definissant la ligne
         * \param y2 : valeur en ordonnee du deuxieme point definissant la ligne
         */
        virtual void dessineLigne(float x1, float y1, float x2, float y2) const = 0;

        /**
         * Dessine un cercle
         * \param x1 : valeur en abscisse du centre du cercle
         * \param y1 : valeur en ordonnee du centre du cercle
         * \param rayon : rayon du cercle
         */
        virtual void dessineCercle(float x, float y, float rayon) const = 0;

        /**
         * Dessine un polygone
         * \param xs : valeurs en abscisse des points definissant le contour du polygone
         * \param ys : valeurs en ordonnee des points definissant le contour du polygone
         */
        virtual void dessinePolygone(const vector<float> &xs, const vector<float> &ys) const = 0;

        /**
         * Detruit la classe de dessin
         */
        virtual ~Dessin() {};

    };

}

#endif
