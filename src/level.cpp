#include "levels.h"

void LoadLevel(int level, SDL_Renderer *renderer) {
    ifstream inFile;
    stack<Entity *> enemies;
    if (level == 1) {
        inFile.open("levels/level1.txt");
    }
    if (!inFile) {
        cout << "File failed to open." << endl;
    }


}
