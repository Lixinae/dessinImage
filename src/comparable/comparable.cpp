#include "comparable/comparable.hpp"

namespace comparateur {

	ostream &operator<<(ostream &os, const Comparateur &comparateur) {
		return (os << comparateur.toString());
	};

}
