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
    drawing.dessineLigne(Point(100, 100), Point(500, 500));
    drawing.dessineLigne(Point(500, 500), Point(400, 200));
    drawing.dessineCercle(Point(500, 500), 50);
    //drawing.dessineLigne(Point(100, 100), Point(500, 500));
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
