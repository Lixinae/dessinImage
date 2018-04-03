#include "comparable/comparable.hpp"

namespace comparable {

	ostream &operator<<(ostream &os, const Comparateur &comparateur) {
		return (os << comparateur.toString());
	};

}
