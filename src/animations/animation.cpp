#include "animation.h"
#include "sprite_sheet.h"

Animation::Animation(const vector<int>& frameIndices, float framesPerSecond)
    : frameIndices(frameIndices), framesPerSecond(framesPerSecond)
{
    this->currentTime = 0;
    this->currentIndex = 0;
    this->looping = true;
    this->finished = false;
}

void Animation::update(float deltaTime)
{
    // exit if the animation is done and loop is turned off
    if (finished && !looping)
    {
        return;
    }

    // increase deltatime and find frameduration
    this->currentTime += deltaTime;
    float frameDuration = 1.0 / framesPerSecond;

    while (currentTime >= frameDuration)
    {
        currentTime -= frameDuration;
        currentIndex++;

        if (currentIndex >= frameIndices.size())
        {
            if (looping)
            {
                currentIndex = 0;
            }
            else
            {
                currentIndex = frameIndices.size() - 1;
                finished = true;
            }
        }
    }
}

void Animation::reset()
{
    this->finished = false;
    this->currentIndex = 0;
    this->currentTime = 0;
}

int Animation::getCurrentFrameIndex() const
{
    return this->frameIndices.at(currentIndex);
}

bool Animation::isFinished() const
{
    return this->finished;
}

void Animation::setLoop(bool loop)
{
    this->looping = loop;
}

void AnimationRender::render(SDL_Renderer* renderer, const SpriteSheet& sheet,
                             const Animation& animation,
                             const SDL_Rect& destRect)
{
    int frameIndex = animation.getCurrentFrameIndex();
    SDL_Rect srcRect = sheet.getFrameRect(frameIndex);
    SDL_Texture* texture = sheet.getTexture();

    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
