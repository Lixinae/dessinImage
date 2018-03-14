#ifndef DESSINIMAGE_RECTANGLE_HPP
#define DESSINIMAGE_RECTANGLE_HPP

#include <ostream>
#include "figure.hpp"

namespace figure {

    class Rectangle : public Figure {

    public:

        static Rectangle temoin;

        explicit Rectangle();

        explicit Rectangle(const Point &upperLeft, const Point &upperRight, const Point &lowerLeft,
                           const Point &lowerRight);

        shared_ptr<Figure> copy() const override;

        /**
         * Renvoie le nom utilise pour identifier un Rectangle
         * \return le nom utilise pour identifier un Rectangle
         */
        string nom() const override;

        void deplacer(const Point &trans) override;
        
        /**
         * Realise une transformation decrite par une matrice sur le rectangle
         * \param matrice : tranformation a appliquer
         */
        void tranformation(const Matrice2D & matrice);

        /**
		 * Realise une translation sur la figure
		 * \param x : valeur de la translation en abscisse
		 * \param y : valeur de la translation en ordonnnee
		 */
        void translation(int x, int y) override;

        /**
         * Realise une rotation sur la figure
         * \param thetat : valeur de l'angle de rotation en radian
         */
        void rotation(float theta) override;

        /**
         * Realise une homothetie sur la figure
         * \param k : valeur de l'homothetie
         */
        void homothetie(float k) override;

        /**
         * Dessine le Rectangle dans la classe de dessin en argument
         * \param dessin : classe de dessin
         */
        void dessiner(const Dessin &dessin) const override;

        double surface() const override;

        double perimetre() const override;

        void afficher(ostream &os = cout) const override;

        const Point &get_upperLeft() const;

        const Point &get_upperRight() const;

        const Point &get_lowerLeft() const;

        const Point &get_lowerRight() const;

    private:

        Point _upperLeft;
        Point _upperRight;
        Point _lowerLeft;
        Point _lowerRight;

    };
}
#endif 
