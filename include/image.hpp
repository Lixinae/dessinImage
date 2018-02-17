
#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include "figure.hpp"
#include <set>

/**
 * Politique uniforme d'allocation m�moire
 * Toutes les figures sont allou�es dynamiquement
 * Une image les m�morise via un tableau de pointeurs de figures
 */
class Image : public Figure {

private:
    /**
     * Origine de la figure
     */
    Point _origine;

    /**
    * Conteneur de figures allou�es dynamiquement
    */
    std::set<std::shared_ptr<Figure>> m_setFigure;
    std::vector<std::shared_ptr<Figure>> m_vectorFigure;

public:

    static Image temoin;

    Image() : _origine(Point(0, 0)), m_setFigure(), m_vectorFigure() {};

    Image(const Point &a) : _origine(a), m_setFigure(), m_vectorFigure() {}

    /**
     * contructeur de copie profonde
     */
    Image(const Image &image);

    virtual std::shared_ptr<Figure> copy() const;

    virtual ~Image() {
        m_setFigure.clear();
        //m_vectorFigure.clear();
    }

    const std::shared_ptr<Figure> getFigure(int index) const {
        auto it = m_setFigure.begin();
        std::advance(it, index);
        auto val = *it;
        return val;
//        return m_vectorFigure[index];
    }

    int getNombre() const {
        return m_setFigure.size();
//        return m_vectorFigure.size();
    }

    Point getOrigine() const {
        return _origine;
    }

    void ajouter(const Figure &f);

    void deplacer(const Point &trans) override;

    void dessiner(ostream &os = cout) const override;

    double surface() const override;

    void afficher(ostream &os = cout) const override;


};

#endif
