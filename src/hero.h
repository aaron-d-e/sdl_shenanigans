#ifndef DRAWING_H
#define DRAWING_H
#include <SDL2/SDL.h>


class Hero {
  public:
    Hero(SDL_Rect rect);
    void drawHeroRect(SDL_Renderer *renderer);
    void setHeroColor(Uint8, Uint8, Uint8, Uint8);

  private:
    SDL_Rect rect;
    Uint8 r, g, b, a;
};

#endif
