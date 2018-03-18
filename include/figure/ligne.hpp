#ifndef LIGNE_H
#define LIGNE_H

#include "figure.hpp"

namespace figure {

    class Ligne : public Figure {

    public:

		/**
		 * Temoin de la classe Ligne
		 */
        static Ligne temoin;

		/**
         * Construit une ligne
         * \param a : origine de la ligne
         * \param b : extremite de la ligne
         */
        explicit Ligne(const Point &a, const Point &b);
        
        /**
         * Renvoie le point d'origine de la ligne
         * \return le point d'origine de la ligne
         */
		Point getOrigine() const;
        
        /**
         * Renvoie le point d'extremite de la ligne
         * \return le point d'extremite de la ligne
         */
		Point getExtremite() const;
		
		/**
         * Realise une copie profonde de la ligne
         * \return une copie profonde de la ligne
         */
        shared_ptr<Figure> copy() const override;
        
        /**
		 * Renvoie le nom utilise pour identifier une ligne
		 * \return le nom utilise pour identifier une ligne
		 */
		string nom() const override;

		 /**
         * Realise une transformation decrite par une matrice sur la ligne
         * \param matrice : tranformation a appliquer
         */
        void tranformation(const Matrice2D & matrice);

       /**
        * Dessine la ligne dans la classe de dessin en argument
        * \param dessin : classe de dessin
        */
		void dessiner(const Dessin &dessin) const override;

		/**
         * Renvoie le point d'origine de la ligne
         * \return le point d'origine de la ligne
         */
        Point origine() const override;

		/**
         * Calcule la surface de la ligne
         * \return la surface de la ligne
         */
		double surface() const override;

		/**
         * Calcule le perimetre de la ligne
         * \return le perimetre de la ligne
         */
		double perimetre() const override;

		/**
         * Affiche la ligne dans un flux
         * \param os : le flux
         * \return le flux
         */
        void afficher(ostream &os = cout) const override;

    private:

        Point _origine;
        Point _extremite;

    };

}

#endif

