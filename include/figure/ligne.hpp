#ifndef LIGNE_H
#define LIGNE_H

#include <transformation/matrice2D.hpp>
#include "figure.hpp"

namespace figure {

    class Ligne : public Figure {

    public:

        static Ligne temoin;

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

		double surface() const override;

		double perimetre() const override;

        void afficher(ostream &os = cout) const override;

    private:

        Point _origine;
        Point _extremite;

    };

}

#endif

