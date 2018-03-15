#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "matrice2D.hpp"

namespace figure {

    using namespace std;
    using namespace transformation;

    class Point {

    public:

        /**
         * Construit un point vide
         */
        explicit Point();

        /**
         * Construit un point
         * \param x : la valeur du point en abscisse
         * \param y : la valeur du point en ordonnee
         */
        explicit Point(float x, float y);

        /**
         * Renvoie la valeur en abscisse du point
         * \return la valeur en abscisse du point
         */
        float getX() const;

        /**
         * Renvoie la valeur en ordonnee du point
         * \return la valeur en ordonnee du point
         */
        float getY() const;

		/**
		 * Applique la transformation representee par la matrice au point
		 * \param matrice : matrice de transformation
		 */
		void transforme(const Matrice2D &matrice);

		/**
         * Renvoie le resultat du produit matriciel entre une matrice de transformation en un point
         * \param x : la matrice de transformation
         * \param y : le point
         * \return le resultat du produit matriciel entre une matrice de transformation en un point
         */
		friend Point operator* (const Matrice2D &matrice, const Point &point);

        /**
         * Ecrit un point dans un flux
         * \param os : le flux
         * \param p : le point a ecrire
         * \return le flux
         */
        friend ostream &operator<<(ostream &os, const Point &p);

    private:

        float _x;
        float _y;

    };

}

#endif
