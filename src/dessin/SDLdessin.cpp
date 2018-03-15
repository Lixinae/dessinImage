#include <dessin/SDLdessin.hpp>
#include <cmath>
#include <stdexcept>

namespace dessin {

    SDLdessin::SDLdessin(int width, int height) : 
		m_width(width),
		m_height(height),
		m_window(nullptr),
		m_renderer(nullptr) {
    }

    SDLdessin::SDLdessin(const SDLdessin &) : SDLdessin(800,600) {

    }

    SDLdessin &SDLdessin::operator=(const SDLdessin &) {
		// todo copy-swap idiom
        return *this;
    }

	SDLdessin::~SDLdessin() {
		SDL_DestroyWindow(m_window);
	};

    void SDLdessin::initialise() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            throw std::runtime_error("SDL could not be initialized: " + string(SDL_GetError()));
		}
        if (SDL_CreateWindowAndRenderer(m_width, m_height, 0, &m_window, &m_renderer) < 0) {
			throw std::runtime_error("Window could not be created: " + string(SDL_GetError()));
		}
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    }

// todo
    void SDLdessin::dessineLigne(float x1, float y1, float x2, float y2) const {
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(m_renderer,
                           static_cast<int>(std::round(x1)), static_cast<int>(std::round(y1)),
                           static_cast<int>(std::round(x2)), static_cast<int>(std::round(y2)));
        SDL_RenderPresent(m_renderer);

    }

    void SDLdessin::dessineCercle(float x, float y, float rayon) const {
        draw_circle(m_renderer,
                    static_cast<int>(std::round(x)), static_cast<int>(std::round(y)),
                    static_cast<int>(std::round(rayon)),
                    255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderPresent(m_renderer);
    }

    void SDLdessin::set_pixel(SDL_Renderer *rend, int x, int y, int r, int g, int b, int a) const {
        SDL_SetRenderDrawColor(rend,
			static_cast<Uint8>(r), static_cast<Uint8>(g), static_cast<Uint8>(b), static_cast<Uint8>(a));
        SDL_RenderDrawPoint(rend, x, y);
    }

    void SDLdessin::draw_circle(SDL_Renderer *surface,
                                int n_cx, int n_cy, int radius,
                                int r, int g, int b, int a) const {
        auto error = (double) -radius;
        double x = (double) radius - 0.5;
        auto y = 0.5;
        double cx = n_cx - 0.5;
        double cy = n_cy - 0.5;

        while (x >= y) {
            set_pixel(surface, (int) (cx + x), (int) (cy + y), r, g, b, a);
            set_pixel(surface, (int) (cx + y), (int) (cy + x), r, g, b, a);

            if (x != 0) {
                set_pixel(surface, (int) (cx - x), (int) (cy + y), r, g, b, a);
                set_pixel(surface, (int) (cx + y), (int) (cy - x), r, g, b, a);
            }

            if (y != 0) {
                set_pixel(surface, (int) (cx + x), (int) (cy - y), r, g, b, a);
                set_pixel(surface, (int) (cx - y), (int) (cy + x), r, g, b, a);
            }

            if (x != 0 && y != 0) {
                set_pixel(surface, (int) (cx - x), (int) (cy - y), r, g, b, a);
                set_pixel(surface, (int) (cx - y), (int) (cy - x), r, g, b, a);
            }

            error += y;
            ++y;
            error += y;

            if (error >= 0) {
                --x;
                error -= x;
                error -= x;
            }
        }
    }

    void SDLdessin::dessinePolygone(const vector<float> &xs, const vector<float> &ys) const {
		if (xs.size() != ys.size()) {
			throw std::invalid_argument("xs and ys have not the same size");
		}
		unsigned int n = xs.size();
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        for (unsigned int i = 0; i < n; i++) {
            int x1 = static_cast<int>(std::round(xs[i]));
            int y1 = static_cast<int>(std::round(ys[i]));
            int x2 = static_cast<int>(std::round(xs[(i + 1)%n]));
            int y2 = static_cast<int>(std::round(ys[(i + 1)%n]));
            SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);
        }
        SDL_RenderPresent(m_renderer);
    }

    void SDLdessin::attendTouche() const {
        bool done = false;
        while (!done) {
            SDL_Event event{};
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_KEYDOWN) {
                    done = true;
                }
                if (event.type == SDL_QUIT) {
                    exit(0);
                }
            }
        }
    }

    void SDLdessin::nettoie() const {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(m_renderer);
    }

}

