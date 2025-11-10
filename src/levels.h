#ifndef LEVELS_H
#define LEVELS_H
#pragma once

#include "entity.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_ENEMIES = 4;

class GameManager {
    // TODO:
    //  1) create and parse json to get level data
    //  2) store data within class object
    //  3) load level function with enemies from json
    //  4) create and delete levels when level changes
    //  5) create a new inventory class that stores player rewards - maybe this
    //  gets stores in a csv for reload each start, gamemanager updates this csv

  public:
    GameManager(int level);
    ~GameManager();

    void Init();

    void RenderEnemies(SDL_Renderer *renderer);

    int GetEnemyCount();

	Entity* GetTargetEnemy(int index) const;

  private:
    // load level file into filename
    void LoadFile();
    // set values from file
    void ReadFile();

	void CheckEntityHealth();

  private:
    int level;
    int locationIndex;
    int numOfEnemies;
    string filename;
    SDL_Rect locations[MAX_ENEMIES];
    vector<Entity *> enemies;
};
#endif
