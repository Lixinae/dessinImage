#include <sstream>
#include <figure/cercle.hpp>///////rm
#include <figure/triangle.hpp>////////////rm
#include <figure/rectangle.hpp>////////////rm
#include <figure/filtrage.hpp>
#include <dessin/SDLdessin.hpp>
#include <figure/serialisationJSON.hpp>
#include <condition/estPetite.hpp>

namespace figure {

	using namespace std;
	using namespace figure;
	using namespace calcul;
	using namespace dessin;
    using namespace condition;

	void main() {

		const Serialisation & serialisation = SerialisationJSON();

		SDLdessin dessin(800, 800);
		dessin.initialise();
	
		/*	
        Ligne l(Point(420, 520), Point(730, 620));
        Ligne l2(Point(200, 500), Point(340, 640));
        Ligne l3(Point(340, 500), Point(200, 640));
        Cercle c(Point(140, 180), 80);
        Cercle c2(Point(580, 300), 140);
        Cercle c3(Point(580, 300), 80);
        Cercle c4(Point(580, 110), 40);
        Cercle c5(Point(480, 135), 40);
        Cercle c6(Point(408, 210), 40);
        Triangle t(Point(50, 290), Point(250, 290), Point(100, 580));
        Rectangle r(Point(400, 500), Point(750, 640));
        Image image(Point(400,400));
        image.ajouter(c);
        image.ajouter(t);
        image.ajouter(l2);
        image.ajouter(l3);
        Image image2(Point(575,570));
        image2.ajouter(r);
        image2.ajouter(l);
        Image image3(Point(580,300));
        image3.ajouter(c2);
        image3.ajouter(c3);
        image3.ajouter(c4);
        image3.ajouter(c5);
        image3.ajouter(c6);
        image.ajouter(image2);
        image.ajouter(image3);
        //serialisation.sauvegarde("./data/demo.json", image);
		vector<shared_ptr<Figure>> fs = {
			make_shared<Image>(image3),
			make_shared<Cercle>(c2),
			make_shared<Image>(image)
		};
		serialisation.sauvegarde_conteneur("data/figures.json", fs);
		*/
	
        //shared_ptr<Figure> figure = serialisation.charge("data/demo.json");
        //figure->dessiner(dessin);
        //dessin.attendTouche();
        
        vector<shared_ptr<Figure>> figures = serialisation.charge_conteneur("data/figures.json");
        //figures[2]->dessiner(dessin);
		//dessin.attendTouche();
        
        for (const auto & figure : figures) {
			figure->dessiner(dessin);
			dessin.attendTouche();
			dessin.nettoie();
		}
        
    }

}

int WinMain() {
    figure::main();
    return 0;
}

int main() {
    figure::main();
    return 0;
}

