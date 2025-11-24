#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
using namespace std;
#pragma once

class SpriteSheet
{
   public:
    SpriteSheet(SDL_Renderer* renderer, const string& filename, int frameWidth,
                int frameHeight);
    ~SpriteSheet();

    SDL_Rect getFrameRect(int frameIndex) const;
    SDL_Texture* getTexture() const;
    int getFrameWidth() const;
    int getFrameHeight() const;
    int getTotalFrames() const;

   private:
    SDL_Texture* texture;
    int frameWidth, frameHeight;
    int framesPerRow;
    int totalFrames;
};

#endif
