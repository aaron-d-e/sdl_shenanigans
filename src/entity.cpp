#include "entity.h"

Entity::Entity(SDL_Rect rect) {
    this->rect.x = rect.x;
    this->rect.y = rect.y;
    this->rect.w = rect.w;
    this->rect.h = rect.h;

    health = 100;
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

    health = 100;
}

void Entity::DrawEntityRect(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
}

void Hero::TakeDamage(int damage) {
    if (this->health > 0) {
        health -= damage;
    }
}
void Enemy::TakeDamage(int damage) {
    if (this->health > 0) {
        health -= damage;
    }
	cout << "Enemy is taking damage" << endl;
}

void Hero::BasicAttack(Entity *target) { target->TakeDamage(baseDamage); }
void Enemy::BasicAttack(Entity *target) { target->TakeDamage(baseDamage); }
