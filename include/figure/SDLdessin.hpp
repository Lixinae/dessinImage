#ifndef DESSINIMAGE_SDLDRAWING_HPP
#define DESSINIMAGE_SDLDRAWING_HPP

#include <figure/dessin.hpp>
#include <SDL.h>

namespace figure {
	
    class SDLdessin : public Dessin {
	
    public:
    
        SDLdessin(int width, int height);

        /**
         * Initialise la classe de dessin
         */
        void initialise();

        /**
         * Dessine une ligne
         * \param p1 : premiere point definissant la ligne
         * \param p2 : deuxieme point definissant la ligne
         */
        void dessineLigne(const Point &p1, const Point &p2) const override;

        /**
         * Dessine un cercle
         * \param centre : centre du cercle
         * \param rayon : rayon du cercle
         */
        void dessineCercle(const Point &centre, float rayon) const override;

        /**
         * Dessine un polygone
         * \param points : points definissant le contour du polygone
         */
        void dessinePolygone(const vector<Point> &points) const override;

        /**
        * Met la fenetre en attente jusqu'à utilisation d'une touche du clavier
        */
        void attendTouche() const;

        /**
         * Nettoie la fenetre de rendu
         */
        void nettoie() const;

        /**
         * Detruit la classe de dessin
         */
        ~SDLdessin();

	private:
    
        int m_width;
        int m_height;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

        SDLdessin(const SDLdessin &);

        SDLdessin &operator=(const SDLdessin &);

        void set_pixel(SDL_Renderer *rend, int x, int y, int r, int g, int b, int a) const;

        void draw_circle(SDL_Renderer *surface, int n_cx, int n_cy, int radius, int r, int g, int b, int a) const;

    };
    
}

#endif
