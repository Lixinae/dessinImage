/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr�ation : 2013-12-21
 * description      : impl�m�ntation d'une classe d�crivant une Image dans une hi�rachie de figures
 */

#include "image.hpp"

namespace figure {

static void afficherAux(ostream &os, const Image &image, int niveau);

/**
 * L'image t�moin est une variable de classe
 */
Image Image::temoin = Image();


Image::Image(const Image &image) : _origine(image._origine), m_setFigure(image.m_setFigure),
                                   m_vectorFigure(image.m_vectorFigure) {
}

/**
 * Fonction virtuelle de copie
 */
shared_ptr<Figure> Image::copy() const {
    auto res = std::shared_ptr<Image>(new Image(this->_origine));
//    res->m_vectorFigure = this->m_vectorFigure;
    res->m_setFigure = this->m_setFigure;
    return res;
}


/**
 * ajout d' une figure � une image
 */
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
    m_setFigure.insert(f.copy());
//    m_vectorFigure.push_back(f.copy());

}

/**
 * D�placement-translation de valeur le point p
 * toutes les figures de l'image sont �galement d�plac�es
 */
void Image::deplacer(const Point &p) {
    _origine += p;
    for (auto fig:m_setFigure) {
        fig->deplacer(p);
    }
}

/**
 * Le dessin se limite � un affichage
 */
void Image::dessiner(ostream &os) const {
    os << *this << endl;
}

double Image::surface() const {
    double res = 0;
    for (auto fig:m_setFigure) {
        res += fig->surface();
    }
    return res;
}

void Image::afficher(ostream &os) const {
    afficherAux(os, *this, 0);
}

static void afficherAux(ostream &os, const Image &image, int niveau) {
    int j;
    for (j = 0; j < niveau; j++) {
        os << "\t";
    }
    os << "BEGIN IMAGE : " << image.getOrigine() << " " << image.getNombre() << " figures " << endl;
    for (int i = 0; i < image.getNombre(); i++) {
        const auto *imageIn = dynamic_cast<const Image *> (image.getFigure(i).get());
        if (imageIn != nullptr) {
            afficherAux(os, *imageIn, niveau + 1);
        } else {
            for (j = 0; j < niveau; j++) {
                os << "\t";
            }
            image.getFigure(i)->afficher(os);
        }
    }
    for (j = 0; j < niveau; j++) {
        os << "\t";
    }
    os << "END IMAGE" << endl;
}

}
