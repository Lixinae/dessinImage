#include <sstream>
#include <figure/image.hpp>
#include <condition/condition.hpp>
#include <figure/SDLdessin.hpp>

using namespace std;
using namespace figure;
using namespace dessin;
using namespace condition;


void mainFunction() {
	
    SDLdessin dessin(800, 600);
    dessin.initialise();

    // todo

    dessin.dessineCercle(500, 500, 50);

    dessin.dessinePolygone(
		{100, 500, 400, 125, 200},
		{100, 500, 200, 150, 300}
	);

    dessin.attendTouche();

    dessin.nettoie(); // nettoie la fenetre des ob
    dessin.dessineLigne(200, 100, 500, 500);
    dessin.dessineLigne(100, 500, 400, 200);
    dessin.attendTouche();

}

int WinMain() {
    mainFunction();
    return 0;
}

int main() {
    mainFunction();
    return 0;
}
