#ifndef CERCLE_H
#define CERCLE_H

#include "figure.hpp"

namespace figure {

    class Cercle : public Figure {

    public:

		/**
		 * Temoin de la classe Cercle
		 */
        static Cercle temoin;

		/**
         * Construit un cercle
         */
        explicit Cercle();

		/**
         * Construit un cercle
         * \param centre : centre du cercle
         */
        explicit Cercle(const Point &centre);

		/**
         * Construit un cercle
         * \param centre : centre du cercle
         * \param rayon : rayon du cercle
         */
        explicit Cercle(const Point &center, float rayon);

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

        /**
        * Realise une transformation decrite par une matrice sur le cercle
        * \param matrice : tranformation a appliquer
        */
        void tranformation(const Matrice2D &matrice);

		/**
         * Realise une copie profonde du cercle
         * \return une copie profonde du cercle
         */
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

		/**
         * Renvoie le point d'origine du cercle
         * \return le point d'origine du cercle
         */
        Point origine() const override;

		/**
         * Calcule la surface du cercle
         * \return la surface du cercle
         */
        double surface() const override;

		/**
         * Calcule le perimetre du cercle
         * \return le perimetre du cercle
         */
        double perimetre() const override;

		/**
         * Affiche le cercle dans un flux
         * \param os : le flux
         * \return le flux
         */
        void afficher(ostream &os = cout) const override;

    private:

        Point _centre;
        float _rayon;

    };

}

#endif
