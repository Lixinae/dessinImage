#ifndef FILTRAGE_H
#define FILTRAGE_H

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
		template <template <class T> class Container>
		static int compterSi(const Container<const Figure *> & figures, const Condition & condition);

		/**
		 * Suppression superficielle des figures d'un conteneur satisfaisant la condition
		 * Supprime les figures de l'image en les désallouant
		 * Si la figure est une image alors ses figures sont également désallouées
		 * Si une image contient une image alors les figures de cette dernière ne sont pas supprimées
		 * \param figures : conteneur de figures
		 * \param condition : condition a verifier
		 * \return true si au moins une figure a ete suprrime, false sinon
		 */
		template <template <class T> class Container>
		static bool supprimerSi(Container<const Figure *> &figures, const Condition & condition);
		
		/**
		 * Suppression profonde des figures d'un conteneur satisfaisant la condition
		 * Supprime les figures de l'image en les désallouant
		 * Si la figure est une image alors ses figures sont également désallouées
		 * Si une image contient une image alors les figures de cette dernière sont supprimées
		 * \param figures : conteneur de figures
		 * \param condition : condition a verifier
		 * \return true si au moins une figure a ete suprrime, false sinon
		 */
		template <template <class T> class Container>
		static bool supprimerSiProfond(Container<const Figure *> &figures, const Condition & condition);
	
	};
	
}

#endif
