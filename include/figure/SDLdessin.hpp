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
         * \param x1 : valeur en abscisse du premier point definissant la ligne
         * \param y1 : valeur en ordonnee du premier point definissant la ligne
         * \param x2 : valeur en abscisse du deuxieme point definissant la ligne
         * \param y2 : valeur en ordonnee du deuxieme point definissant la ligne
         */
        void dessineLigne(float x1, float y1, float x2, float y2) const override;

		/**
         * Dessine un cercle
         * \param x1 : valeur en abscisse du centre du cercle
         * \param y1 : valeur en ordonnee du centre du cercle
         * \param rayon : rayon du cercle
         */
        void dessineCercle(float x, float y, float rayon) const override;

        /**
         * Dessine un polygone
         * \param xs : valeurs en abscisse des points definissant le contour du polygone
         * \param ys : valeurs en ordonnee des points definissant le contour du polygone
         */
        void dessinePolygone(const vector<float> &xs, const vector<float> &ys) const override;

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
