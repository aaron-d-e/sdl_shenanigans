#ifndef DRAWING_H
#define DRAWING_H
#pragma once

#include <SDL2/SDL.h>

class Entity {
  public:
    // CONSTRUCTORS
    Entity(SDL_Rect rect); // black as default
    Entity(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a); // colorized
    virtual ~Entity() = default;

    // RENDER FUNCTIONS
    void drawEntityRect(SDL_Renderer *renderer);

    // GAME FUNCTIONS
    int getHealth() { return health; }
    virtual void takeDamage(int damage);
    virtual void
    basicAttack(Entity *enemy) = 0; // must be implemented in children classes

  protected:
    SDL_Rect rect;
    Uint8 r, g, b, a;
    int health;
};

class Hero : public Entity {
  public:
    // CONSTRUCTORS
    Hero(SDL_Rect rect) : Entity(rect) {}
    Hero(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
        : Entity(rect, r, g, b, a) {}

    // GAME FUNCTIONS
    void basicAttack(Entity *enemy);

  private:
    int level;
    int baseDamage = 20;
};

class Enemy : public Entity {
  public:
    // CONSTRUCTORS
    Enemy(SDL_Rect rect) : Entity(rect) {}
    Enemy(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
        : Entity(rect, r, g, b, a) {}

    // GAME FUNCTIONS
    void basicAttack(Entity *enemy);

  private:
    SDL_Rect main, left, right;
    int baseDamage = 10;
};

#endif
