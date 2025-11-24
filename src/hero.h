#ifndef HERO_H
#define HERO_H

#include <iostream>
#include "animations/sprite_sheet.h"
#pragma once

class Hero
{
   public:
    Hero(SDL_Rect dest);
    virtual ~Hero() = default;

    int getHealth();
    virtual void TakeDamage(int damage) = 0;
    virtual void BasicAttack(/* enemy goes here */) = 0;

    // TODO: give an inherited class and write animations for each inherited
    // classes, could update parent to include virtual functions
   protected:
    SDL_Rect dest;
    int health;
};

#endif
