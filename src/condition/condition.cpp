#include "condition/condition.hpp"

namespace condition {

	ostream &operator<<(ostream &os, const Condition &condition) {
		return (os << condition.toString());
	};

}
