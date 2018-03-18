#include <algorithm>
#include <iostream>
#include "figure/filtrage.hpp"
#include "figure/image.hpp"
#include "figure/ligne.hpp"
#include "figure/cercle.hpp"
#include <random>
#include <effolkronium/random.hpp>

namespace figure {

	using Random = effolkronium::random_static;

	Figure *Filtrage::getUneFigure(int x, int y) {
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

	list<const Figure *> Filtrage::creerFigures(int n) {
		list<const Figure *> figures(n);
		int i = 0;
		std::generate(begin(figures), end(figures), [&i]() {
			const auto figure = getUneFigure(10*i, 10*i);
			i++;
			return figure;
		});
		return figures;
	}

	int Filtrage::compterSi(list<const Figure *> figures, Condition *condition) {
		int compteur = 0;
		std::for_each(cbegin(figures), cend(figures), [&compteur, condition](const auto & figure){
			if (condition->verif(figure)) {
				compteur++;
			}
		});
		return compteur;
	}

	bool Filtrage::supprimerSi(list<const Figure *> &figures, Condition *condition) {
		bool flag = false;
		auto it(figures.begin());
		auto end(figures.end());
		while (it != end) {
			if (condition->verif(*it)) {
				flag = true;
				it = figures.erase(it);
			} else {
				++it;
			}
		}
		return flag;
	}
	
	bool Filtrage::supprimerSiProfond(list<const Figure *> &figures, Condition *condition) {
		bool flag = false;
		if (figures.empty())
			return true;
		auto it(figures.begin());
		auto end(figures.end());
		while (it != end) {
			if (condition->verif(*it)) {
				flag = true;
				it = figures.erase(it);
			} else {
				auto *image = dynamic_cast<const Image *>(*it);
				if (image != 0) {
					auto figuresImage = list<const Figure *>();
					for (int i = 0; i < image->getNombre(); i++) {
						figuresImage.push_back(image->getFigure(i).get());
					}
					flag = Filtrage::supprimerSiProfond(figuresImage, condition);
					it = figures.erase(it);
					auto *nouvelle = new Image();
					auto it2(figuresImage.begin());
					auto end2(figuresImage.end());
					for (; it2 != end2; ++it2) {
						nouvelle->ajouter(**it2);
					}
					figures.push_front(nouvelle);
				} else {
					++it;
				}
			}
		}
		return flag;
	}

}
