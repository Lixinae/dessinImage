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
