#include <sstream>
#include <figure/image.hpp>
#include <condition/condition.hpp>
#include <figure/SDLdessin.hpp>

using namespace std;
using namespace figure;
using namespace condition;


void mainFunction() {
    SDLdessin drawing(800, 600);
    drawing.initialise();

    // todo

    drawing.dessineCercle(Point(500, 500), 50);

    drawing.dessinePolygone({Point(100, 100), Point(500, 500), Point(400, 200), Point(125, 150), Point(200, 300)});

    //drawing.dessineLigne(Point(100, 100), Point(500, 500));
    drawing.attendClick();

    drawing.cleanWindow(); // nettoie la fenetre des ob
    drawing.dessineLigne(Point(200, 100), Point(500, 500));
    drawing.dessineLigne(Point(100, 500), Point(400, 200));
    drawing.attendClick();

}

int WinMain() {
    mainFunction();
    return 0;
}

int main() {
    mainFunction();
    return 0;
}
