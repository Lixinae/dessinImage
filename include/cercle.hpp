#ifndef CERCLE_H
#define CERCLE_H

#include "figure.hpp"

namespace figure {

    class Cercle : public Figure {

    public:

        static Cercle temoin;

        explicit Cercle();

        explicit Cercle(const Point &centre);

		explicit Cercle(const Point &center, int rayon);

		void deplacer(const Point &trans) override;

		/**
		 * Realise une translation sur le cercle
		 * \param x : valeur de la translation en abscisse
		 * \param y : valeur de la translation en ordonnnee
		 */
		void translation(int x, int y) override;

		/**
		 * Realise une rotation sur le cercle
		 * \param thetat : valeur de l'angle de rotation en radian
		 */
		void rotation(float theta) override;

		/**
		 * Realise une homothetie sur le cercle
		 * \param k : valeur de l'homothetie
		 */
		void homothetie(float k) override;

		shared_ptr<Figure> copy() const override;

		void dessiner(ostream &os = cout) const override;

		double surface() const override;

		double perimetre() const override;

		void afficher(ostream &os = cout) const override;

		private:

			Point _centre;
			int _rayon;

    };

}

#endif
