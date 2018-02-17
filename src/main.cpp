#include <sstream>
#include <figure/image.hpp>
#include <condition/condition.hpp>
#include <SDL/SDL.h>

using namespace std;
using namespace figure;
using namespace condition;


void mainFunction() {
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        cerr << "Erreur d'initialisation de la SDL" << endl;
        exit(EXIT_FAILURE);
    }
    SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);

    SDL_Event event{};


    auto continu = true;
    while (continu) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                continu = false;
                break;
            default:
                break;
        }
        /*
 * TODO
 * Do stuff here
 */
    }


    SDL_Quit();
}

int WinMain() {
    mainFunction();
    return 0;
}

int main() {
    mainFunction();
    return 0;
}
