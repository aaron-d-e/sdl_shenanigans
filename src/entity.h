#ifndef DRAWING_H
#define DRAWING_H
#include <SDL2/SDL.h>

class Entity {
  public:
    Entity(SDL_Rect rect); // black as default
    Entity(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a); // colorized
    void drawEntityRect(SDL_Renderer *renderer);

  private:
    SDL_Rect rect;
    Uint8 r, g, b, a;
    int health;
};

class Hero : public Entity {
  public:
    Hero(SDL_Rect rect) : Entity(rect) {}
    Hero(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
        : Entity(rect, r, g, b, a) {}

	void basicAttack(Entity enemy, int damage);

  private:
	int level;

};

class Enemy : public Entity {
  public:
    Enemy(SDL_Rect rect) : Entity(rect) {}
    Enemy(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
        : Entity(rect, r, g, b, a) {}
};

#endif
