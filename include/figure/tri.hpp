#ifndef TRI_H
#define TRI_H

#include "figure/figure.hpp"
#include "comparable/comparateur.hpp"
#include <list>

namespace figure {

	using namespace std;
	using namespace comparateur;

	class Tri {

	public:

		/**
		 * Tri un conteneur de figures selon un comparateur
		 * \param figures : conteneur de figures
		 * \param comparateur : critere de comparaison
		 */
		static void trier(list<shared_ptr<Figure>> & figures, const Comparateur & comparateur);

	};
	
}

#endif
