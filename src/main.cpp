#include "debug.h"
#include "levels.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include "sprite_sheet.h"
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

    /*
    int flags = IMG_INIT_PNG;
    int initStatus = IMG_Init(flags);
    if ((initStatus & flags) != flags)
    {
        cout << "SDL2_Image format not initialized (might not be available)"
             << endl;
    }

    SDL_Surface* image;
    image = IMG_Load("images/blastoise.png");
    if (!image)
    {
        cout << "Image could not be loaded." << endl;
    }

    SDL_Texture* testPNG = SDL_CreateTextureFromSurface(renderer, image);

    */

    SpriteSheet characSheet(renderer, "", 0, 0);

    bool running = true;
    SDL_Event event;
    while (running)
    {
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

        // clear the scene
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // SDL_RenderCopy(renderer, testPNG, NULL, NULL);

        // present render
        SDL_RenderPresent(renderer);
    }

    // quit sdl2 image
    // IMG_Quit();

    // free sdl surface
    //  SDL_FreeSurface(image);

    // destroy texture
    // SDL_DestroyTexture(testPNG);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
