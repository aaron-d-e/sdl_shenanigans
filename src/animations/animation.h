#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <SDL2/SDL_image.h>
#include "sprite_sheet.h"
using namespace std;
#pragma once

class Animation
{
   public:
    Animation(const vector<int>& frameIndices, float framesPerSecond);

    void update(float deltaTime);
    void reset();
    int getCurrentFrameIndex() const;
    bool isFinished() const;
    void setLoop(bool loop);

   private:
    vector<int> frameIndices;
    float framesPerSecond;
    float currentTime;
    int currentIndex;
    bool looping;
    bool finished;
};

class AnimationRender
{
   public:
    static void render(SDL_Renderer* renderer, const SpriteSheet& sheet,
                       const Animation& animation, const SDL_Rect& destRect);
};

#endif
