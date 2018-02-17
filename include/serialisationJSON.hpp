#ifndef SERIALISATIONJSON_H
#define SERIALISATIONJSON_H

#include "serialisation.hpp"
#include <json.hpp>
#include "ligne.hpp"
#include "cercle.hpp"
#include "image.hpp"
#include "triangle.hpp"

namespace figure {

    using namespace std;
    using json = nlohmann::json;

    class SerialisationJSON : Serialisation {

    public:

        /**
         * Sauvegarde la figure dans un fichier au format JSON
         * \param fichier : nom du fichier
         * \param figure : figure a sauvegarder
         */
        void sauvegarde(const string &fichier, const Figure &figure) const override;

        /**
         * Charge une figure depuis un fichier JSON
         * \param fichier : nom du fichier
         * \return la figure stockee dans le fichier JSON
         */
        Figure *charge(const string &fichier) const override;

    private:

        Figure *jsonVersFigure(const json &jsonFigure) const;

        Point jsonVersPoint(const json &jsonPoint) const;

        json figureVersJson(const Figure &figure) const;

        json figureVersJson(const Ligne &figure) const;

        json figureVersJson(const Cercle &figure) const;

        json figureVersJson(const Image &figure) const;

        json figureVersJson(const Triangle &figure) const;

        json pointVersJson(const Point &point) const;

    };

}

#endif
