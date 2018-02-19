#include "estPetite.hpp"
#include <string>

namespace condition {

EstPetite::EstPetite(double seuil) : _seuil(seuil) {
	
}

string EstPetite::toString() const {
	return "La surface EST PLUS PETITE QUE " + std::to_string(_seuil);
}

bool EstPetite::verif(const Figure *f) const {
	return f->surface() < _seuil;
}

}
