#include <sstream>
#include <list>
#include <algorithm>
#include <image.hpp>
#include <ligne.hpp>
#include <cercle.hpp>
#include <condition.hpp>
#include <estPetite.hpp>
#include <estUn.hpp>
#include <et.hpp>
#include <non.hpp>
#include <filtrage.hpp>
#include <serialisation.hpp>

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
