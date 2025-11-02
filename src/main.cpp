#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window *window =
        SDL_CreateWindow("SDL2 + CMake on Arch Linux", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
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

	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

    SDL_Delay(5000); // Keep window open for 2 seconds

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
