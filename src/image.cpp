#include "image.hpp"

#include <algorithm>

namespace figure {

Image Image::temoin = Image();

Image::Image() : Image(Point()) {
	
};

Image::Image(const Point &a) : _origine(a), _figures() {
	
}

Image::Image(const Image &image) : _origine(image._origine), _figures() {
	for (const auto & figure : image._figures) {
		_figures.insert(figure->copy());
	}
}

shared_ptr<Figure> Image::copy() const {
    return std::make_shared<Image>(*this);
}

const std::shared_ptr<Figure> Image::getFigure(int index) const {
	auto it = std::cbegin(_figures);
	std::advance(it, index);
	return *it;
}

int Image::getNombre() const {
	return _figures.size();
}

Point Image::getOrigine() const {
	return _origine;
}

void Image::ajouter(const Figure &f) {
    if (f == *this)
        return;

    /** Code pour du partage d'instances allou�es dynamiquement
     * n�cessite des compteurs de r�f�rence pour leur lib�ration m�moire
        en C ==> ABANDON
        _tableau[_nombre++] = (Figure *) (&f);
        en C++: du const_cast
        _tableau[_nombre++] = const_cast<Figure *> (&f);
    */
    _figures.insert(f.copy());

}

void Image::deplacer(const Point &p) {
    _origine += p;
    std::for_each(
		std::cbegin(_figures),
		std::cend(_figures), 
		[p](const auto & figure){figure->deplacer(p);}
	);
}

void Image::dessiner(ostream &os) const {
    os << *this << endl;
}

double Image::surface() const {
    double res = std::accumulate(
		std::cbegin(_figures),
		std::cend(_figures), 
		0,
		[](auto acc, const auto & figure) {return acc + figure->surface();}
	);
	return res;
}

void Image::afficher(ostream &os) const {
    afficherAux(os, *this, 0);
}

void Image::afficherAux(ostream &os, const Image &image, int niveau) {
	string shift(niveau, '\t');
    os << shift << "BEGIN IMAGE : " << image._origine << " " << image._figures.size() << " figures " << endl;
    for (const auto & figure : image._figures) {
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
