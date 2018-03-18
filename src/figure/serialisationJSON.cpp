#include "figure/serialisationJSON.hpp"

#include <fstream>

namespace figure {

    void SerialisationJSON::sauvegarde(const string &fichier, const Figure &figure) const {
        ofstream fichierFigure(fichier);
        fichierFigure << figureVersJson(figure).dump(4);
        fichierFigure.close();
    }
    
    void SerialisationJSON::sauvegarde_conteneur(const string &fichier, const vector<shared_ptr<Figure>> &figures) const {
		ofstream fichierFigures(fichier);
        fichierFigures << figuresVersJson(figures).dump(4);
        fichierFigures.close();
	}

    shared_ptr<Figure> SerialisationJSON::charge(const string &fichier) const {
        json jsonFigure;
        ifstream fichierFigure(fichier);
        fichierFigure >> jsonFigure;
        fichierFigure.close();
        return jsonVersFigure(jsonFigure);
    }
    
    vector<shared_ptr<Figure>> SerialisationJSON::charge_conteneur(const string &fichier) const {
		json jsonFigures;
        ifstream fichierFigures(fichier);
        fichierFigures >> jsonFigures;
        fichierFigures.close();
        return jsonVersFigures(jsonFigures);
	}

	vector<shared_ptr<Figure>> SerialisationJSON::jsonVersFigures(const json &jsonFigures) const {
		vector<shared_ptr<Figure>> figures;
		for (const auto &it : jsonFigures) {
			figures.push_back(jsonVersFigure(it));
		}
		return figures;
	}

    shared_ptr<Figure> SerialisationJSON::jsonVersFigure(const json &jsonFigure) const {
        string type = jsonFigure["nom"];
        if (type == Ligne::temoin.nom()) {
            return make_shared<Ligne>(
                    jsonVersPoint(jsonFigure["args"]["origine"]),
                    jsonVersPoint(jsonFigure["args"]["extremite"])
            );
        }
        if (type == Triangle::temoin.nom()) {
            return make_shared<Triangle>(
                    jsonVersPoint(jsonFigure["args"]["point1"]),
                    jsonVersPoint(jsonFigure["args"]["point2"]),
                    jsonVersPoint(jsonFigure["args"]["point3"])
            );
        }
        if (type == Rectangle::temoin.nom()) {
            return make_shared<Rectangle>(
                    jsonVersPoint(jsonFigure["args"]["upperLeft"]),
                    jsonVersPoint(jsonFigure["args"]["lowerRight"])
            );
        }
        if (type == Cercle::temoin.nom()) {
            return make_shared<Cercle>(
                    jsonVersPoint(jsonFigure["args"]["centre"]),
                    jsonFigure["args"]["rayon"]
            );
        }
        if (type == Image::temoin.nom()) {
            shared_ptr<Image> image = make_shared<Image>(jsonVersPoint(jsonFigure["args"]["origine"]));
            for (const auto &it : jsonFigure["args"]["figures"]) {
                image->ajouter(*(jsonVersFigure(it)));
            }
            return image;
        }
        throw invalid_argument(type + " n'est pas un type de figure valide");
    }

    Point SerialisationJSON::jsonVersPoint(const json &jsonPoint) const {
        return Point(jsonPoint["x"], jsonPoint["y"]);
    }

    json SerialisationJSON::figuresVersJson(const vector<shared_ptr<Figure>> & figures) const {
		json jsonFigures;
		for (const auto & figure : figures) {
            jsonFigures.push_back(figureVersJson(*figure));
        }
		return jsonFigures;
	}	
	
    json SerialisationJSON::figureVersJson(const Figure &figure) const {
        if (figure.nom() == Ligne::temoin.nom()) {
            return figureVersJson(dynamic_cast<const Ligne &>(figure));
        }
        if (figure.nom() == Cercle::temoin.nom()) {
            return figureVersJson(dynamic_cast<const Cercle &>(figure));
        }
        if (figure.nom() == Triangle::temoin.nom()) {
            return figureVersJson(dynamic_cast<const Triangle &>(figure));
        }
        if (figure.nom() == Rectangle::temoin.nom()) {
            return figureVersJson(dynamic_cast<const Rectangle &>(figure));
        }
        if (figure.nom() == Image::temoin.nom()) {
            return figureVersJson(dynamic_cast<const Image &>(figure));
        }
        throw invalid_argument("type de figure non supporte");
    }

    json SerialisationJSON::figureVersJson(const Ligne &figure) const {
        json jsonFigure;
        jsonFigure["nom"] = Ligne::temoin.nom();
        jsonFigure["args"]["origine"] = pointVersJson(figure.getOrigine());
        jsonFigure["args"]["extremite"] = pointVersJson(figure.getExtremite());
        return jsonFigure;
    }

    json SerialisationJSON::figureVersJson(const Cercle &figure) const {
        json jsonFigure;
        jsonFigure["nom"] = Cercle::temoin.nom();
        jsonFigure["args"]["centre"] = pointVersJson(figure.getCentre());
        jsonFigure["args"]["rayon"] = figure.getRayon();
        return jsonFigure;
    }

    json SerialisationJSON::figureVersJson(const Image &figure) const {
        json jsonFigure;
        jsonFigure["nom"] = Image::temoin.nom();
        jsonFigure["args"]["origine"] = pointVersJson(figure.getOrigine());
        json jsonSubFigures;
        for (int i = 0; i < figure.getNombre(); i++) {
            json jsonSubFigure = figureVersJson(*(figure.getFigure(i)));
            jsonSubFigures.push_back(jsonSubFigure);
        }
        jsonFigure["args"]["figures"] = jsonSubFigures;
        return jsonFigure;
    }
    
    json SerialisationJSON::figureVersJson(const Triangle &figure) const {
        json jsonFigure;
        jsonFigure["nom"] = Triangle::temoin.nom();
        jsonFigure["args"]["point1"] = pointVersJson(figure.get_point1());
        jsonFigure["args"]["point2"] = pointVersJson(figure.get_point2());
        jsonFigure["args"]["point3"] = pointVersJson(figure.get_point3());
        return jsonFigure;
    }

    json SerialisationJSON::pointVersJson(const Point &point) const {
        json jsonPoint;
        jsonPoint["x"] = point.getX();
        jsonPoint["y"] = point.getY();
        return jsonPoint;
    }

    json SerialisationJSON::figureVersJson(const Rectangle &figure) const {
        json jsonFigure;
        jsonFigure["nom"] = Rectangle::temoin.nom();
        jsonFigure["args"]["upperLeft"] = pointVersJson(figure.get_upperLeft());
        jsonFigure["args"]["lowerRight"] = pointVersJson(figure.get_lowerRight());
        return jsonFigure;
    }

}
