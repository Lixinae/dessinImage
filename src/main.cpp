#include <sstream>
#include <figure/image.hpp>
#include <condition/condition.hpp>
#include <figure/SDLDrawing.hpp>

using namespace std;
using namespace figure;
using namespace condition;


void mainFunction() {
    SDLDrawing drawing(800, 600);
    drawing.dessineLigne(Point(0, 0), Point(3, 3));
}

int WinMain() {
    mainFunction();
    return 0;
}

int main() {
    mainFunction();
    return 0;
}
