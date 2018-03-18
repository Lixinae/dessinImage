#include <sstream>
#include <figure/cercle.hpp>///////
#include <figure/triangle.hpp>////////////
#include <figure/rectangle.hpp>////////////
#include <figure/filtrage.hpp>
#include <dessin/SDLdessin.hpp>

namespace figure {

	using namespace std;
	using namespace figure;
	using namespace calcul;
	using namespace dessin;

	void main() {

		auto x = Filtrage::creerFigures(5);
		std::cerr << x.size() << std::endl;

		SDLdessin dessin(800, 600);
		dessin.initialise();

		Cercle c(Point(50, 50), 20);
		Triangle t(Point(10, 10), Point(200, 10), Point(50, 300));
		Rectangle r(Point(100, 100), Point(500, 200));

		c.dessiner(dessin);
		t.dessiner(dessin);
		dessin.attendTouche();

		Matrice2D transformations = Matrice2D::translation(10, 220) * Matrice2D::rotation(-0.8);
		t.tranformation(transformations);

		dessin.nettoie();
		c.dessiner(dessin);
		t.dessiner(dessin);
		r.dessiner(dessin);
		dessin.attendTouche();

	}

}

int WinMain() {
    figure::main();
    return 0;
}

int main() {
    figure::main();
    return 0;
}

