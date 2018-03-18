#include "figure/filtrage.hpp"

#include <algorithm>
#include <iostream>
#include "figure/image.hpp"

namespace figure {

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
