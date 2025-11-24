#include "sprite_sheet.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>

SpriteSheet::SpriteSheet(SDL_Renderer* renderer, const string& filename,
                         int frameWidth, int frameHeight)
    : texture(NULL), frameWidth(frameWidth), frameHeight(frameHeight)

{
    // check for sdl2 image initStatus
    int flags = IMG_INIT_PNG;
    int initStatus = IMG_Init(flags);
    if ((initStatus & flags) != flags)
    {
        cout << "SDL2_Image format not initialized (might not be available)"
             << endl;
    }

    // create surface with the passed filename, is deleted later in the
    // constructor
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if (!surface)
    {
        cout << "Surface not created within constructor." << endl;
        exit(-1);
    }

    // create texture from the above surface, uses renderer passed by
    // constructor
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture)
    {
        cout << "Texture not created in constructor." << endl;
        exit(-1);
    }

    // get height and width of loaded image
    int sheetWidth = surface->w;
    int sheetHeight = surface->h;

    // free surface because we grabbed all the needed info
    SDL_FreeSurface(surface);

    // initialize other variables, may need to be changed depending on format of
    // sheet
    framesPerRow = sheetWidth / frameWidth;
    int rows = sheetHeight / frameHeight;
    totalFrames = framesPerRow * rows;
}

SpriteSheet::~SpriteSheet()
{
    SDL_DestroyTexture(texture);
}

// getter functions
SDL_Texture* SpriteSheet::getTexture() const
{
    return texture;
}

int SpriteSheet::getFrameHeight() const
{
    return frameHeight;
}

int SpriteSheet::getFrameWidth() const
{
    return frameWidth;
}

int SpriteSheet::getTotalFrames() const
{
    return totalFrames;
}

// calculates the row and col index and returns the SDL_Rect of that sprite
// index
SDL_Rect SpriteSheet::getFrameRect(int frameIndex) const
{
    int row = frameIndex / framesPerRow;
    int col = frameIndex % framesPerRow;

    return {col * frameWidth, row * frameHeight, frameWidth, frameHeight};
}
