#ifndef FILTRAGE_H
#define FILTRAGE_H

#include <list>
#include "figure/figure.hpp"
#include "condition/condition.hpp"

namespace figure {

	using namespace std;
	using namespace condition;

	class Filtrage {

	public:

		/**
		 * Retourne le nombre de figures d'une liste de figures vérifiant la condition dans un conteneur
		 * \param figures : conteneur de figures
		 * \param condition : condition a verifier
		 * \return le nombre de figures d'une liste de figures vérifiant la condition dans un conteneur
		 */
		static int compterSi(list<const Figure *> figures, Condition *condition);

		/**
		 * Suppression superficielle des figures d'un conteneur satisfaisant la condition
		 * Supprime les figures de l'image en les désallouant
		 * Si la figure est une image alors ses figures sont également désallouées
		 * Si une image contient une image alors les figures de cette dernière ne sont pas supprimées
		 * \param figures : conteneur de figures
		 * \param condition : condition a verifier
		 * \return true si au moins une figure a ete suprrime, false sinon
		 */
		static bool supprimerSi(list<const Figure *> &figures, Condition *condition);
		
		/**
		 * Suppression profonde des figures d'un conteneur satisfaisant la condition
		 * Supprime les figures de l'image en les désallouant
		 * Si la figure est une image alors ses figures sont également désallouées
		 * Si une image contient une image alors les figures de cette dernière sont supprimées
		 * \param figures : conteneur de figures
		 * \param condition : condition a verifier
		 * \return true si au moins une figure a ete suprrime, false sinon
		 */
		static bool supprimerSiProfond(list<const Figure *> &figures, Condition *condition);


		/**
		 * Retourne une figure aléatoire
		 * \param x : valeur en abscisse du centre de la figure
		 * \param y : valeur en ordonnee du centre de la figure
		 * \return une figure aléatoire
		 */
		static Figure * getUneFigure(int x, int y);

		/**
		 * Retourne un conteneur de figures aléatoires
		 * \param n : taille du conteneur
		 * \return un conteneur de figures aléatoires 
		 */
		static list<const Figure *> creerFigures(int n);
	
	};
	
}

#endif
