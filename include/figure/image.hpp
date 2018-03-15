#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include "figure.hpp"
#include <set>
#include <numeric>

namespace figure {

    class Image : public Figure {

    public:

		/**
		 * Temoin de la classe Figure
		 */
        static Image temoin;
	
		/**
		 * Construit une image
		 */
		explicit Image();

		/**
		 * Construit une image
		 * \param p : origine de l'image
		 */
        explicit Image(const Point &p);

		/**
		 * Constructeur de copie
		 * \param image : image a copier
		 */
        Image(const Image &image);

		/**
         * Renvoie l'origine de l'image
         * \return l'origine de l'image
         */
		Point getOrigine() const;
		
		/**
		 * Renvoie le nombre de figure dans l'image
		 * \return le nombre de figure dans l'image
		 */
		int getNombre() const;
	
		/**
		 * Realise un acces par indice aux figures de l'image
		 * \param index : indice de la figure
		 * \return figure a l'indice en argument
		 */
		const shared_ptr<Figure> getFigure(int index) const;
	
		/**
         * Realise une copie profonde de l'image
         * \return une copie profonde de l'image
         */
        std::shared_ptr<Figure> copy() const override;

		/**
         * Renvoie le nom utilise pour identifier une image
         * \return le nom utilise pour identifier une image
         */
		string nom() const override;

		/**
        * Realise une transformation decrite par une matrice sur l'image
        * \param matrice : tranformation a appliquer
        */
		void tranformation(const Matrice2D &matrice);

		/**
		 * Ajoute une figure a l'image
		 * \param f : figure a ajouter
		 */
		void ajouter(const Figure &f);

	   /**
		* Dessine l'image dans la classe de dessin en argument
		* \param dessin : classe de dessin
		*/
		void dessiner(const Dessin &dessin) const override;

		/**
         * Calcule la surface de l'image
         * \return la surface de l'image
         */
		double surface() const override;

		/**
         * Calcule le perimetre de l'image
         * \return le perimetre de l'image
         */
		double perimetre() const override;

		/**
         * Affiche l'image dans un flux
         * \param os : le flux
         * \return le flux
         */
		void afficher(ostream &os = cout) const override;

		private:

			Point _origine;

			set<std::shared_ptr<Figure>> _figures;

			static void afficherAux(ostream &os, const Image &image, int niveau);

	};

}

#endif
