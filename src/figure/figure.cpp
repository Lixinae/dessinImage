#include "figure/figure.hpp"

#include <effolkronium/random.hpp>
#include "figure/image.hpp"
#include "figure/ligne.hpp"
#include "figure/cercle.hpp"

namespace figure {

	using Random = effolkronium::random_static;

	Figure * Figure::getUneFigure(int x, int y) {
		int lowBound = 0;
		int upBound = 1999;
		int n = Random::get(0, 2);
		switch (n) {
			case 0:
				return new Cercle(Point(x, y), Random::get(lowBound, upBound));
			case 1:
				return new Ligne(Point(x, y), Point(Random::get(lowBound, upBound), Random::get(lowBound, upBound)));
			case 2:
				return new Image(Point(x, y));
			default:
				throw std::domain_error("invalid shape id");
		}
	}

	list<const Figure *> Figure::creerFigures(int n) {
		list<const Figure *> figures(n);
		int i = 0;
		std::generate(begin(figures), end(figures), [&i]() {
			const auto figure = getUneFigure(10*i, 10*i);
			i++;
			return figure;
		});
		return figures;
	}

	bool Figure::operator==(const Figure &f) const {
		return (this == &f); //TODO egalite memoire ?
	}

	ostream &operator<<(ostream &os, const Figure &figure) {
		figure.afficher(os);
		return os;
	}
	
}
