#include <SDLDrawing.hpp>


namespace figure {

    SDLDrawing::SDLDrawing(int width, int height) {
        initialise();
    }

    void SDLDrawing::initialise() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            cout << "SDL could not initialize! SDL_Error: %s\n" << endl;
        }
    }


    void SDLDrawing::dessineLigne(const Point &p1, const Point &p2) {

    }

    void SDLDrawing::dessineCercle(const Point &centre, float rayon) {

    }

    void SDLDrawing::dessinePolygone(const vector<Point> &points) {

    }


}

