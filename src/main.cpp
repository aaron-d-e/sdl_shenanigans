#include "debug.h"
#include "levels.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include "animations/sprite_sheet.h"
#include "animations/animation.h"
using namespace std;

int main()
{
    const int WIDTH = 1200;
    const int HEIGHT = 1000;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cerr << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "SDL2 + CMake on Arch Linux", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if (!window)
    {
        cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        return 1;
    }

    SpriteSheet characSheet(renderer, "images/FlyingBomb1-Sheet.png", 32, 32);

    // establish vector with animation frames

    vector<int> flyingFrames = {0, 1, 2, 3};

    Animation flyingAnimation(flyingFrames, 12.0f);

    // make Animation* current animation
    Animation* currentAnim = &flyingAnimation;

    Uint32 lastTime = SDL_GetTicks();
    int frameCounter = 0;

    bool running = true;
    while (running)
    {
        frameCounter++;
        // deltaTime calculations for physics and anims
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }
        }

        // update animation here
        currentAnim->update(deltaTime);

        // clear the scene
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // SDL_RenderCopy(renderer, testPNG, NULL, NULL);
        //
        // render animation here at dest SDL_Rect
        SDL_Rect dest = {100, 100, 64, 64};
        // use AnimationRender::render here
        AnimationRender::render(renderer, characSheet, *currentAnim, dest);

        // present render
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
