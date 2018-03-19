#ifndef TRI_H
#define TRI_H

#include "figure/figure.hpp"
#include "comparable/comparable.hpp"
#include <list>

namespace figure {

	using namespace std;
	using namespace comparable;

	class Tri {

	public:

		/**
		 * Tri un conteneur de figures selon un comparable
		 * \param figures : conteneur de figures
		 * \param comparable : critere de comparaison
		 */
		static void trier(list<shared_ptr<Figure>> & figures, const Comparable & comparable);

	};
	
}

#endif
