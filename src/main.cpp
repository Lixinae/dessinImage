#include <sstream>
#include <figure/image.hpp>
#include <condition/condition.hpp>
#include <figure/SDLdessin.hpp>

using namespace std;
using namespace figure;
using namespace condition;


void mainFunction() {
	
    SDLdessin dessin(800, 600);
    dessin.initialise();

    // todo

    dessin.dessineCercle(Point(500, 500), 50);

    dessin.dessinePolygone({Point(100, 100), Point(500, 500), Point(400, 200), Point(125, 150), Point(200, 300)});

    dessin.attendTouche();

    dessin.nettoie(); // nettoie la fenetre des ob
    dessin.dessineLigne(Point(200, 100), Point(500, 500));
    dessin.dessineLigne(Point(100, 500), Point(400, 200));
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
