//
// Created by ValasNaerth on 14/03/2018.
//

#ifndef DESSINIMAGE_SDLDRAWING_HPP
#define DESSINIMAGE_SDLDRAWING_HPP

#include <figure/dessin.hpp>
#include <SDL.h>

namespace figure {
    class SDLdessin : public Dessin {
    private:
        int m_width = 800, m_height = 600;
        SDL_Window *m_window = nullptr;

        //The surface contained by the window
        SDL_Renderer *m_renderer = nullptr;

        SDLdessin(const SDLdessin &);

        SDLdessin &operator=(const SDLdessin &);
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
        * Met la fenetre en attente d'un evenement pour la maintenir ouverte
        */
        void attendClick() const;
        /**
         * Detruit la classe de dessin
         */
        ~SDLdessin() {
            SDL_DestroyWindow(m_window);
        };
    };
}

#endif //DESSINIMAGE_SDLDRAWING_HPP
