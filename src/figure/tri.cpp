#include "figure/tri.hpp"

namespace figure {

	void Tri::trier(list<shared_ptr<Figure>> & figures, const Comparateur & comparateur) {
		figures.sort([&comparateur](const auto f1, const auto f2) {
			return comparateur.compare(f1.get(), f2.get());
		});
	}

}
