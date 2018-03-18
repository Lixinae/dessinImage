#ifndef FIGUREH
#define FIGUREH

#include <iostream>
#include "point.hpp"
#include <memory>
#include <cmath>
#include "dessin/dessin.hpp"
#include <calcul/matrice2D.hpp>

constexpr double PI = acos(-1);

namespace figure {

    using namespace std;
    using namespace dessin;
    using namespace calcul;

    class Figure {

    public:

        /**
         * Realise une copie profonde de la figure
         * \return une copie profonde de la figure
         */
        virtual shared_ptr<Figure> copy() const = 0;

        /**
         * Renvoie le nom de la figure
         * \return le nom de la figure
         */
        virtual string nom() const = 0;

        /**
         * Detruit la figure
         */
        virtual ~Figure() {};

        /**
         * Realise une transformation decrite par une matrice sur la figure
         * \param matrice : tranformation a appliquer
         */
        virtual void tranformation(const Matrice2D & matrice) = 0;
        
        /**
         * Dessine la figure dans la classe de dessin en argument
         * \param dessin : classe de dessin
         */
        virtual void dessiner(const Dessin &dessin) const = 0;

        /**
         * Affiche la figure dans un flux
         * \param os : le flux
         * \return le flux
         */
        virtual void afficher(ostream &os) const = 0;

        /**
         * Renvoie le point d'origine de la figure
         * \return le point d'origine de la figure
         */
        virtual Point origine() const = 0;
        
        /**
         * Calcule la surface de la figure
         * \return la surface de la figure
         */
        virtual double surface() const = 0;

        /**
         * Calcule le perimetre de la figure
         * \return le perimetre de la figure
         */
        virtual double perimetre() const = 0;
        
        /**
         * Teste l'egalite de deux figures
         * \param f : figure a tester
         * \return true si les figures sont les memes, faux sinon
         */
        bool operator==(const Figure &f) const;
        
        /**
         * Ecrit une figure dans un flux
         * \param os : le flux
         * \param figure : la figure a ecrire
         * \return le flux
         */
        friend ostream &operator<<(ostream &os, const Figure &figure);

    };

}

#endif
