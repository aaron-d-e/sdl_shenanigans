#ifndef DRAWING_H
#define DRAWING_H
#include <SDL2/SDL.h>


class Hero {
  public:
    Hero(SDL_Rect rect); //black as default
    Hero(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a); //colorized
    void drawHeroRect(SDL_Renderer *renderer);

  private:
    SDL_Rect rect;
    Uint8 r, g, b, a;
};

#endif
