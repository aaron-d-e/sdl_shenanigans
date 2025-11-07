#include "levels.h"

const int WIDTH = 1200;
const int HEIGHT = 1000;

GameManager::GameManager(int level) {
    this->level = level; // current level for loading file
    numOfEnemies = 0;    // number of enemies to push into vector
    locationIndex = 0;   // location on screen to render to
    filename = "";       // will crash if not initialized later

    // load screen location into array
    locations[0] = {WIDTH - 75 - 250, 400, 75, 75};
    locations[1] = {WIDTH - 375 - 250, 200, 75, 75};
}
GameManager::~GameManager() {
    for (auto &ptr : enemies) {
        delete ptr; // iterate through to delete all enemies
    }
    enemies.clear();
}
void GameManager::LoadFile() {

    switch (level) {

    case 0:
        this->filename = "levels/level0.txt";
    }
}

void GameManager::ReadFile() {

    ifstream inFile;
    inFile.open(filename);

    if (!inFile) {
        cout << "File failed to open." << endl;
        assert(inFile); // crash program with assert
    }

    while (inFile) {
        string category;
        inFile >> category;

        if (category == "numOfEnemies") {
            int x;
            inFile >> x;
            this->numOfEnemies = x;
        }
        for (int i = 0; i < numOfEnemies; i++) {
            string type;
            inFile >> type;
            if (type == "Enemy") {
                assert(locationIndex < 4); // crash if more than 4 enemies
                enemies.push_back(new Enemy(locations[locationIndex]));
            }

            // rest of type checks here
            locationIndex++; // place enemy in empty position on-screen
        }
    }
}

void GameManager::Init() {
    this->LoadFile();
    this->ReadFile();
}

int GameManager::GetEnemyCount() { return numOfEnemies; }

void GameManager::RenderEnemies(SDL_Renderer *renderer) {
    for (int i = 0; i < numOfEnemies; i++) {
        enemies.at(i)->drawEntityRect(renderer);
    }
}
