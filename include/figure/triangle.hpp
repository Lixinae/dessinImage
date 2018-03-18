#ifndef DESSINIMAGE_TRIANGLE_HPP
#define DESSINIMAGE_TRIANGLE_HPP

#include "figure/figure.hpp"

namespace figure {
	
    class Triangle : public Figure {
    
    public:
    
		/**
		 * Temoin de la classe Triangle
		 */
        static Triangle temoin;

		/**
		 * Construit un triangle
		 */
        explicit Triangle();

		/**
		 * Construit un triangle
		 * \param point1 : premier point du triangle
		 * \param point2 : deuxieme point du triangle
		 * \param point3 : troisieme point du triangle
		 */
        explicit Triangle(const Point &point1, const Point &point2, const Point &point3);

		/**
         * Realise une copie profonde du triangle
         * \return une copie profonde du triangle
         */
        shared_ptr<Figure> copy() const override;

        /**
         * Renvoie le nom utilise pour identifier un triangle
         * \return le nom utilise pour identifier un triangle
         */
        string nom() const override;
        
		/**
         * Realise une transformation decrite par une matrice sur le triangle
         * \param matrice : tranformation a appliquer
         */
        void tranformation(const Matrice2D & matrice);

        /**
         * Dessine le triangle dans la classe de dessin en argument
         * \param dessin : classe de dessin
         */
        void dessiner(const Dessin &dessin) const override;

		/**
         * Renvoie le point d'origine du triangle
         * \return le point d'origine du triangle
         */
        Point origine() const override;

		/**
         * Calcule la surface du triangle
         * \return la surface du triangle
         */
        double surface() const override;

		/**
         * Calcule le perimetre du triangle
         * \return le perimetre du triangle
         */
        double perimetre() const override;

		/**
         * Affiche le triangle dans un flux
         * \param os : le flux
         * \return le flux
         */
        void afficher(ostream &os = cout) const override;

		/**
         * Renvoie le premier point du triangle
         * \return le premier point du triangle
         */
        const Point &get_point1() const;

		/**
         * Renvoie le deuxieme point du triangle
         * \return le deuxieme point du triangle
         */
        const Point &get_point2() const;

		/**
         * Renvoie le troisieme point du triangle
         * \return le troisieme point du triangle
         */
        const Point &get_point3() const;

    private:
    
        Point _point1;
        Point _point2;
        Point _point3;
    
    };
}

#endif
