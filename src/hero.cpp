#include "hero.h"

Hero::Hero(SDL_Rect rect)
{
    this->dest = rect;
    health = 100;
}

int Hero::getHealth()
{
    return this->health;
}

// inherited classes go here
