#ifndef DEBUG_H
#define DEBUG_H
#pragma once

#include <iostream>
#include <sstream>
#include "levels.h"
using namespace std;

// use only for entity rects
ostream &rectLog(ostream &os, const SDL_Rect &rect, string msg = "") {
    os << "DEBUG: " << msg << "\nx: " << rect.x << "\ny: " << rect.y << endl;

    return os;
}

ostream &damageLog(ostream &os, int health, string msg = "") {
    os << "DEBUG: " << msg << '\n' << health << endl;

    return os;
}

#endif
