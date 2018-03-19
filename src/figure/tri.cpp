#include "figure/tri.hpp"

namespace figure {

	void Tri::trier(list<shared_ptr<Figure>> & figures, const Comparable & comparable) {
		figures.sort([&comparable](const auto f1, const auto f2) {
			return comparable.compare(f1.get(), f2.get());
		});
	}

}
