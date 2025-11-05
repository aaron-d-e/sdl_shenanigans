#include "entity.h"
#include "debug.h"
#include <iostream>

using namespace std;

int main() {

    const int WIDTH = 1200;
    const int HEIGHT = 1000;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "SDL2 + CMake on Arch Linux", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Rect heroRect;
    heroRect.x = 250;
    heroRect.y = HEIGHT - 400;
    heroRect.w = 150;
    heroRect.h = 150;
    Hero hero(heroRect, 0, 0, 255, 1);
	rectLog(cout, heroRect, "Hero Rect");


    SDL_Rect enemyRect;
    enemyRect.x = WIDTH - 150 - 250;
    enemyRect.y = 400;
    enemyRect.w = 150;
    enemyRect.h = 150;
    Enemy enemy(enemyRect, 255, 0, 0, 1);
	rectLog(cout, enemyRect, "Enemy Rect");

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            }
        }
        // clear the scene
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // game render here
        hero.drawEntityRect(renderer);
        enemy.drawEntityRect(renderer);
        // present render
        SDL_RenderPresent(renderer);
    }

    // clean up
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
