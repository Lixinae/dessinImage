#ifndef DESSINIMAGE_RECTANGLE_HPP
#define DESSINIMAGE_RECTANGLE_HPP

#include <ostream>
#include "figure.hpp"

namespace figure {

    class Rectangle : public Figure {

    public:

		/**
		 * Temoin de la classe Rectangle
		 */
        static Rectangle temoin;
	
		/**
		 * Construit un rectangle
		 */
        explicit Rectangle();

		/**
		 * Construit un rectangle
		 * \param upperLeft : coin superieur gauche du rectangle
		 * \param upperLeft : coin inferieur droit du rectangle
		 */
        explicit Rectangle(const Point &upperLeft, const Point &lowerRight);

		/**
         * Realise une copie profonde du rectangle
         * \return une copie profonde du rectangle
         */
        shared_ptr<Figure> copy() const override;

        /**
         * Renvoie le nom utilise pour identifier un Rectangle
         * \return le nom utilise pour identifier un Rectangle
         */
        string nom() const override;

        /**
         * Realise une transformation decrite par une matrice sur le rectangle
         * \param matrice : tranformation a appliquer
         */
        void tranformation(const Matrice2D & matrice);
        
        /**
         * Dessine le Rectangle dans la classe de dessin en argument
         * \param dessin : classe de dessin
         */
        void dessiner(const Dessin &dessin) const override;

		/**
         * Calcule la surface du rectangle
         * \return la surface du rectangle
         */
        double surface() const override;

		/**
         * Calcule le perimetre du rectangle
         * \return le perimetre du rectangle
         */
        double perimetre() const override;

		/**
         * Affiche le rectangle dans un flux
         * \param os : le flux
         * \return le flux
         */
        void afficher(ostream &os = cout) const override;

		/**
         * Renvoie le coin superieur gauche point du rectangle
         * \return le coin superieur gauche point du rectangle
         */
        const Point &get_upperLeft() const;

		/**
         * Renvoie le coin inferieur droit point du rectangle
         * \return le coin inferieur droit point du rectangle
         */
        const Point &get_lowerRight() const;

    private:

        Point _upperLeft;
        Point _lowerRight;

    };
}
#endif 
