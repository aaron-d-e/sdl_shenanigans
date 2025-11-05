#include "entity.h"
#include <iostream>
#include <sstream>
using namespace std;

//use only for entity rects
ostream &rectLog(ostream &os, const SDL_Rect &rect, string msg = "") {
    os << "DEBUG: " << msg << "\nx: " << rect.x << "\ny: " << rect.y << endl;

    return os;
}
