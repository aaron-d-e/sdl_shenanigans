#include "hero.h"

Hero::Hero(SDL_Rect rect) {
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 255;

    this->rect.x = rect.x;
    this->rect.y = rect.y;
    this->rect.w = rect.w;
    this->rect.h = rect.h;
}
Hero::Hero(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->rect.x = rect.x;
    this->rect.y = rect.y;
    this->rect.w = rect.w;
    this->rect.h = rect.h;

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Hero::drawHeroRect(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
}

