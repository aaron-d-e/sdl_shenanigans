#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
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

#endif
