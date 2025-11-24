#ifndef DRAWING_H
#define DRAWING_H
#pragma once

#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

class Entity
{
   public:
    // CONSTRUCTORS
    Entity(SDL_Rect rect);  // black as default
    Entity(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a);  // colorized
    virtual ~Entity() = default;

    // RENDER FUNCTIONS
    void DrawEntityRect(SDL_Renderer* renderer);

    // GAME FUNCTIONS
    int getHealth()
    {
        return health;
    }
    virtual void TakeDamage(int damage) = 0;
    virtual void BasicAttack(
        Entity* target) = 0;  // must be implemented in children classes

   protected:
    SDL_Rect rect;
    Uint8 r, g, b, a;
    int health;
};

class Hero : public Entity
{
   public:
    // CONSTRUCTORS
    Hero(SDL_Rect rect) : Entity(rect)
    {
        health = 100;
        baseDamage = 10;
    }
    Hero(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
        : Entity(rect, r, g, b, a)
    {
        health = 100;
        baseDamage = 10;
    }

    // GAME FUNCTIONS
    void BasicAttack(Entity* target);
    void TakeDamage(int damage);

   private:
    int level;
    int baseDamage;
};

class Enemy : public Entity
{
   public:
    // CONSTRUCTORS
    Enemy(SDL_Rect rect) : Entity(rect)
    {
        health = 50;
        baseDamage = 10;
    }
    Enemy(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
        : Entity(rect, r, g, b, a)
    {
        health = 50;
        baseDamage = 10;
    }

    // GAME FUNCTIONS
    void BasicAttack(Entity* target);
    void TakeDamage(int damage);

   private:
    SDL_Rect main, left, right;
    int baseDamage;
};

#endif
