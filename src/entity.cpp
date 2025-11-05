#include "entity.h"

Entity::Entity(SDL_Rect rect) {
    this->rect.x = rect.x;
    this->rect.y = rect.y;
    this->rect.w = rect.w;
    this->rect.h = rect.h;
}

Entity::Entity(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->rect.x = rect.x;
    this->rect.y = rect.y;
    this->rect.w = rect.w;
    this->rect.h = rect.h;

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Entity::drawEntityRect(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
}

