#ifndef DESSINIMAGE_TRIANGLE_HPP
#define DESSINIMAGE_TRIANGLE_HPP

#include <matrice2D.hpp>
#include "figure/figure.hpp"

namespace figure {
	
    class Triangle : public Figure {
    
    public:
    
        static Triangle temoin;

        explicit Triangle();

        explicit Triangle(const Point &point1, const Point &point2, const Point &point3);

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

        double surface() const override;

        double perimetre() const override;

        void afficher(ostream &os = cout) const override;

        const Point &get_point1() const;

        const Point &get_point2() const;

        const Point &get_point3() const;

    private:
    
        Point _point1;
        Point _point2;
        Point _point3;
    
    };
}

#endif
