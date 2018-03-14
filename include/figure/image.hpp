
#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include "figure.hpp"
#include <set>
#include <numeric>
#include <matrice2D.hpp>

namespace figure {

    class Image : public Figure {

    public:

        static Image temoin;

        //TODO
        /*explicit*/ Image();

        /*explicit*/ Image(const Point &p);

        /*explicit*/ Image(const Image &image);

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
	
		////todo
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

		void ajouter(const Figure &f);

	   /**
		* Dessine l'image dans la classe de dessin en argument
		* \param dessin : classe de dessin
		*/
		void dessiner(const Dessin &dessin) const override;

		double surface() const override;

		double perimetre() const override;

		void afficher(ostream &os = cout) const override;

		private:

			Point _origine;

			set<std::shared_ptr<Figure>> _figures;

			static void afficherAux(ostream &os, const Image &image, int niveau);

	};

}

#endif
