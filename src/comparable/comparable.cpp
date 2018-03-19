#include "comparable/comparable.hpp"

namespace comparable {

	ostream &operator<<(ostream &os, const Comparable &comparable) {
		return (os << comparable.toString());
	};

}
