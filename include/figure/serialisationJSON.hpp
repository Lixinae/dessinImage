#ifndef SERIALISATIONJSON_H
#define SERIALISATIONJSON_H

#include "figure/serialisation.hpp"
#include <json.hpp>
#include <figure/rectangle.hpp>
#include "figure/ligne.hpp"
#include "figure/cercle.hpp"
#include "figure/image.hpp"
#include "figure/triangle.hpp"

namespace figure {

    using namespace std;
    using json = nlohmann::json;

    class SerialisationJSON : public Serialisation {

    public:

        /**
         * Sauvegarde la figure dans un fichier au format JSON
         * \param fichier : nom du fichier
         * \param figure : figure a sauvegarder
         */
        void sauvegarde(const string &fichier, const Figure &figure) const override;

	   /**
		* Sauvegarde le conteneur de figures dans un fichier au format JSON
		* \param fichier : nom du fichier
		* \param figure : conteneur figure a sauvegarder
		*/
		void sauvegarde_conteneur(const string &fichier, const list<shared_ptr<Figure>> &figures) const override;

        /**
         * Charge une figure depuis un fichier JSON
         * \param fichier : nom du fichier
         * \return la figure stockee dans le fichier JSON
         */
        shared_ptr<Figure> charge(const string &fichier) const override;
        
	   /**
		* Charge un conteneur de figures depuis un fichier JSON
		* \param fichier : nom du fichier
		* \return la figure stockee dans le fichier
		*/
		virtual list<shared_ptr<Figure>> charge_conteneur(const string &fichier) const override;

    private:

        list<shared_ptr<Figure>> jsonVersFigures(const json &jsonFigures) const;
        
        shared_ptr<Figure> jsonVersFigure(const json &jsonFigure) const;

        Point jsonVersPoint(const json &jsonPoint) const;

		json figuresVersJson(const list<shared_ptr<Figure>> & figures) const;	
        
        json figureVersJson(const Figure &figure) const;

        json figureVersJson(const Ligne &figure) const;

        json figureVersJson(const Cercle &figure) const;

        json figureVersJson(const Image &figure) const;

        json figureVersJson(const Triangle &figure) const;

        json figureVersJson(const Rectangle &figure) const;

        json pointVersJson(const Point &point) const;

    };

}

#endif
