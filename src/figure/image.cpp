#include "figure/image.hpp"

#include <algorithm>

namespace figure {

    Image Image::temoin = Image();

    Image::Image() : Image(Point()) {

    };

    Image::Image(const Point &a) : _origine(a), _figures() {

    }

    Image::Image(const Image &image) : _origine(image._origine), _figures() {
        for (const auto &figure : image._figures) {
            _figures.insert(figure->copy());
        }
    }

	Point Image::getOrigine() const {
		return _origine;
	}

    shared_ptr<Figure> Image::copy() const {
        return std::make_shared<Image>(*this);
    }
    
    std::string Image::nom() const {
		return "image";
	}

    const std::shared_ptr<Figure> Image::getFigure(int index) const {
        auto it = std::cbegin(_figures);
        std::advance(it, index);
        return *it;
    }

    int Image::getNombre() const {
        return _figures.size();
    }

    void Image::ajouter(const Figure &f) {
        if (f == *this)
            return;
        _figures.insert(f.copy());
	}
	
	void Image::tranformation(const Matrice2D & matrice) {
		std::for_each(
			std::cbegin(_figures),
			std::cend(_figures), 
			[&matrice](const auto & figure){figure->tranformation(matrice);}
		);
	}

	void Image::dessiner(const Dessin &dessin) const {
		std::for_each(
			std::cbegin(_figures),
			std::cend(_figures), 
			[&dessin](const auto & figure){figure->dessiner(dessin);}
		);
	}

	Point Image::origine() const {
		return _origine;
	}

    double Image::surface() const {
        double res = std::accumulate(
                std::cbegin(_figures),
                std::cend(_figures),
                0,
                [](auto acc, const auto &figure) { return acc + figure->surface(); }
        );
        return res;
    }

    double Image::perimetre() const {
        double res = std::accumulate(
                std::cbegin(_figures),
                std::cend(_figures),
                0,
                [](auto acc, const auto &figure) { return acc + figure->perimetre(); }
        );
        return res;
    }

    void Image::afficher(ostream &os) const {
        afficherAux(os, *this, 0);
    }

    void Image::afficherAux(ostream &os, const Image &image, int niveau) {
        string shift(niveau, '\t');
        os << shift << "BEGIN IMAGE : " << image._origine << " " << image._figures.size() << " figures " << endl;
        for (const auto &figure : image._figures) {
            const auto *imageIn = dynamic_cast<const Image *>(figure.get());
            if (imageIn != nullptr) {
                afficherAux(os, *imageIn, niveau + 1);
            } else {
                os << shift;
                figure->afficher(os);
            }
        }
        os << shift << "END IMAGE" << endl;
    }

}
