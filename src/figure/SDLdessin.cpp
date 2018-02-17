#include <figure/SDLdessin.hpp>
#include <cmath>


namespace figure {

    SDLdessin::SDLdessin(int width, int height) : m_width(width), m_height(height) {
    }

    SDLdessin::SDLdessin(const SDLdessin &) : m_width(800), m_height(600) {

    }

    SDLdessin &SDLdessin::operator=(const SDLdessin &) {
        return *this;
    }

    void SDLdessin::initialise() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        } else {
            //Create window
            if (SDL_CreateWindowAndRenderer(m_width, m_height, 0, &m_window, &m_renderer) < 0) {
                cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
            } else {
                SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            }
        }
    }

// todo
    void SDLdessin::dessineLigne(const Point &p1, const Point &p2) const {
        SDL_RenderClear(m_renderer);
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(m_renderer,
                           static_cast<int>(std::round(p1.getX())), static_cast<int>(std::round(p1.getY())),
                           static_cast<int>(std::round(p2.getX())), static_cast<int>(std::round(p2.getY())));


    }

    void SDLdessin::dessineCercle(const Point &centre, float rayon) const {

    }

    void SDLdessin::dessinePolygone(const vector<Point> &points) const {

    }

    void SDLdessin::attendClick() const {
        bool done = false;
        while (!done) {
            SDL_Event event{};
            SDL_RenderPresent(m_renderer);
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    done = true;
                }
            }
        }


    }


}

