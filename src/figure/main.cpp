#include <sstream>
#include <figure/cercle.hpp>///////todo rm
#include <figure/triangle.hpp>////////////todo rm
#include <figure/rectangle.hpp>////////////todo rm
#include <figure/filtrage.hpp>
#include <dessin/SDLdessin.hpp>
#include <figure/serialisationJSON.hpp>
#include <condition/condition.hpp>
#include <condition/estUn.hpp>
#include <condition/estPetite.hpp>
#include <condition/et.hpp>
#include <condition/non.hpp>

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
        
        const string fich = "data/figures.json";
        
        cout << "Chargement depuis le fichier " << fich << endl;
        
        list<shared_ptr<Figure>> figures = serialisation.charge_conteneur(fich);
        std::vector<shared_ptr<Figure>> vec_figures(begin(figures), end(figures));
        
        const Condition & condition = EstUn(&Cercle::temoin);
        
        cout << "Condition de filtre : " << condition << endl;
        cout << "Nombre de figure respectant la condition : " << Filtrage::compterSi(figures,condition) << endl;
        
        const int index_figure = 0;
        
        const auto figure = vec_figures[index_figure];
		
		cout << "Avant filtrage" << endl;
		cout << *figure << endl;
		
		figure->dessiner(dessin);
		dessin.attendTouche();
		dessin.nettoie();
		
		Filtrage::supprimerSiProfond(figures, condition);
		
		const auto filtered_figure = vec_figures[index_figure];
		
		cout << "Apres filtrage" << endl;
		cout << *filtered_figure << endl;
		
		filtered_figure->dessiner(dessin);
		dessin.attendTouche();
		dessin.nettoie();
        
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

