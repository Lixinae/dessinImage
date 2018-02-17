#ifndef LIGNE_H
#define LIGNE_H

#include "figure.hpp"

namespace figure {

    class Ligne : public Figure {

    public:

        static Ligne temoin;

        explicit Ligne(const Point &a, const Point &b);

        shared_ptr<Figure> copy() const override;

        void deplacer(const Point &trans) override;

		/**
		 * Realise une translation sur la ligne
		 * \param x : valeur de la translation en abscisse
		 * \param y : valeur de la translation en ordonnnee
		 */
		void translation(int x, int y) override;
		
		/**
		 * Realise une rotation sur la ligne
		 * \param thetat : valeur de l'angle de rotation en radian
		 */
		void rotation(float theta) override;
		
		/**
		 * Realise une homothetie sur la ligne
		 * \param k : valeur de l'homothetie
		 */
		void homothetie(float k) override;

       /**
        * Dessine la ligne dans la classe de dessin en argument
        * \param dessin : classe de dessin
        */
		void dessiner(const Dessin &dessin) const override;

		double surface() const override;

		double perimetre() const override;

        void afficher(ostream &os = cout) const override;

    private:

        Point _origine;
        Point _extremite;

    };

}

#endif

