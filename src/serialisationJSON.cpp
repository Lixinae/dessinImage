#include "serialisationJSON.hpp"

#include <fstream>

namespace figure {

void SerialisationJSON::sauvegarde(const string &fichier, const Figure &figure) const {
	ofstream fichierFigure(fichier);
	fichierFigure << figureVersJson(figure).dump(4);
	fichierFigure.close();
}

Figure * SerialisationJSON::charge(const string &fichier) const {
	json jsonFigure;
	ifstream fichierFigure(fichier);
	fichierFigure >> jsonFigure;
	fichierFigure.close();
	return jsonVersFigure(jsonFigure);
}

Figure * SerialisationJSON::jsonVersFigure(const json &jsonFigure) const {
	string type = jsonFigure["nom"];
	if (type == Ligne::temoin.nom()) {
		return new Ligne(
			jsonVersPoint(jsonFigure["args"]["origine"]),
			jsonVersPoint(jsonFigure["args"]["extremite"])
		);
	}
	if (type == Cercle::temoin.nom()) {
		return new Cercle(
			jsonVersPoint(jsonFigure["args"]["centre"]),
			jsonFigure["args"]["rayon"]
		);
	}
	if (type == Image::temoin.nom()) {
		Image * image = new Image(jsonVersPoint(jsonFigure["args"]["origine"]));
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

json SerialisationJSON::figureVersJson(const Figure &figure) const {
	if (figure.nom() == Ligne::temoin.nom()) {
		return figureVersJson(dynamic_cast<const Ligne&>(figure));
	}
	if (figure.nom() == Cercle::temoin.nom()) {
		return figureVersJson(dynamic_cast<const Cercle&>(figure));
	}
	if (figure.nom() == Image::temoin.nom()) {
		return figureVersJson(dynamic_cast<const Image&>(figure));
	}
	throw invalid_argument("type de figure non supporte");
}

json SerialisationJSON::figureVersJson(const Ligne &figure) const {
	json jsonFigure;
	jsonFigure["nom"] = Ligne::temoin.nom();
	jsonFigure["nom"]["args"]["origine"] = pointVersJson(figure.getOrigine());
	jsonFigure["nom"]["args"]["extremeite"] = pointVersJson(figure.getExtremite());
	return jsonFigure;
}

json SerialisationJSON::figureVersJson(const Cercle &figure) const {
	json jsonFigure;
	jsonFigure["nom"] = Cercle::temoin.nom();
	jsonFigure["nom"]["args"]["centre"] = pointVersJson(figure.getCentre());
	jsonFigure["nom"]["args"]["rayon"] = figure.getRayon();
	return jsonFigure;
}

json SerialisationJSON::figureVersJson(const Image &figure) const {
	json jsonFigure;
	jsonFigure["nom"] = Image::temoin.nom();
	jsonFigure["nom"]["args"]["origine"] = pointVersJson(figure.getOrigine());
	json jsonSubFigures;
	for (int i = 0; i < figure.getNombre(); i++) {
		json jsonSubFigure = figureVersJson(*(figure.getFigure(i)));
		jsonSubFigures.push_back(jsonSubFigure);
	}
	jsonFigure["nom"]["args"]["figures"] = jsonSubFigures;
	return jsonFigure;
}

json SerialisationJSON::pointVersJson(const Point &point) const {
	json jsonPoint;
	jsonPoint["x"] = point.getX();
	jsonPoint["y"] = point.getY();
	return jsonPoint;
}

}
