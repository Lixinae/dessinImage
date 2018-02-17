#include <sstream>
#include <list>
#include <algorithm>
#include <figure/image.hpp>
#include <figure/ligne.hpp>
#include <condition/condition.hpp>
#include <condition/estPetite.hpp>
#include <condition/estUn.hpp>
#include <filtrage.hpp>

using namespace std;
using namespace figure;
using namespace condition;

int main() {
	
	Figure *f = new Ligne(Point(),Point());
	Ligne *l = new Ligne(Point(),Point());
	
	EstPetite ll(2);
	
	std::cerr << (typeid(f) == typeid(l)) << std::endl;
	
    return 0;

}
