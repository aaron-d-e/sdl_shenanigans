#include "debug.h"
#include "levels.h"
#include <iostream>
#include <stack>
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

    //---------------------------------------------------------//

    GameManager game(0);

    game.Init();
    cout << "Number of Enemies: " << game.GetEnemyCount() << endl;

    SDL_Rect heroRect;
    heroRect.x = 250;
    heroRect.y = HEIGHT - 400;
    heroRect.w = 150;
    heroRect.h = 150;

    SDL_Rect enemyRect = {WIDTH - 150 - 250, 400, 150, 150};

    Hero *hero = new Hero(heroRect, 0, 0, 255, 1);
    rectLog(cout, heroRect, "Hero Rect");

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
                if (event.key.keysym.sym == SDLK_1) {
                    Entity *enemy = game.GetTargetEnemy(0);
                    if (enemy != NULL) {
                        hero->BasicAttack(enemy);
                    }
                }
                else if (event.key.keysym.sym == SDLK_2) {
                    Entity *enemy = game.GetTargetEnemy(1);
                    if (enemy != NULL) {
                        hero->BasicAttack(enemy);
                    }
                }
            }
        }
        // clear the scene
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // game render here
        hero->DrawEntityRect(renderer);

        if (game.GetEnemyCount() > 0) {
            game.RenderEnemies(renderer);
        }
        else {
            cout << "You won, shutting down..." << endl;
            running = false;
            SDL_RenderPresent(renderer);
            SDL_Delay(1500);
        }

        // present render
        SDL_RenderPresent(renderer);
    }

    // clean up
    if (hero) {
        delete hero;
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
