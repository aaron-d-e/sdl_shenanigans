#include "animation.h"

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
    this->currentTime += deltaTime;
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
