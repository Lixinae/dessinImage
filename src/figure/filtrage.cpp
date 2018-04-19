#include "figure/filtrage.hpp"

#include <algorithm>
#include <iostream>
#include "figure/image.hpp"

namespace figure {

	int Filtrage::compterSi(const list<shared_ptr<Figure>> & figures, const Condition & condition) {
		int compteur = 0;
		std::for_each(cbegin(figures), cend(figures), [&compteur, &condition](const auto & figure){
			if (condition.verif(figure.get())) {
				compteur++;
			}
		});
		return compteur;
	}

	bool Filtrage::supprimerSi(list<shared_ptr<Figure>> &figures, const Condition & condition) {
		bool flag = false;
		auto it(figures.begin());
		auto end(figures.end());
		while (it != end) {
			if (condition.verif(it->get())) {
				flag = true;
				it = figures.erase(it);
			} else {
				++it;
			}
		}
		return flag;
	}
	
	bool supprimerSiImage(Image * image, const Condition & condition) {
		list<shared_ptr<Figure>> figuresImage;
		for (int i = 0; i < image->getNombre(); i++) {
			figuresImage.push_back(image->getFigure(i));
		}
		bool flag = Filtrage::supprimerSiProfond(figuresImage, condition);
		Image newImage(image->getOrigine());
		for (const auto figure : figuresImage) {
			newImage.ajouter(*figure);
		}
		(*image) = newImage;
		return flag;
	}
	
	bool Filtrage::supprimerSiProfond(list<shared_ptr<Figure>> &figures, const Condition & condition) {
		bool flag = false;
		if (figures.empty()) {
			return true;
		}
		auto it(figures.begin());
		auto end(figures.end());
		while (it != end) {
			if (condition.verif(it->get())) {
				flag = true;
				it = figures.erase(it);
			} else {
				Image * image = dynamic_cast<Image *>(it->get());
				if (image != nullptr) {
					bool flagsub = supprimerSiImage(image, condition);
					flag = flag || flagsub;
				}
				++it;
			}
		}
		return flag;
	}

}
