#include <figure/SDLDrawing.hpp>


namespace figure {

    SDLDrawing::SDLDrawing(int width, int height) : m_width(width), m_height(height) {
        initialise();
    }

    void SDLDrawing::initialise() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        } else {
            //Create window
            if (SDL_CreateWindowAndRenderer(640, 480, 0, &m_window, &m_renderer) < 0) {
                cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
            } else {

            }
        }
    }


    void SDLDrawing::dessineLigne(const Point &p1, const Point &p2) {
        SDL_RenderClear(m_renderer);
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(m_renderer,
                           static_cast<int>(p1.getX()), static_cast<int>(p1.getY()),
                           static_cast<int>(p2.getX()), static_cast<int>(p2.getY()));
        SDL_RenderPresent(m_renderer);

    }

    void SDLDrawing::dessineCercle(const Point &centre, float rayon) {

    }

    void SDLDrawing::dessinePolygone(const vector<Point> &points) {

    }


}

