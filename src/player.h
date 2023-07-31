//
// Created by lukas on 15.06.2023.
//

#ifndef RAYLIBSTARTER_PLAYER_H
#define RAYLIBSTARTER_PLAYER_H

#pragma once
#include "masterhead.h"
#include "player.h"
#include "gameobject.h"
#include "Enemy.h"

class gameobject;
class Enemy;
class gameScene;

class player {
public:
    int life = 0;
    int posX = 19;
    int posY = 14;
    int age = 0;
    int stepCounterUp = 0;
    int stepCounterDown = 0;
    int stepCounterRight = 0;
    int stepCounterLeft = 0;
    int keyDownDelay = 15; // Sets the speed of the player - Higher Delay = Slower Player

    gameScene* szene;
    //const bool tileWalkableLookup[13] = {1,1,0,0,0,0,0,0,0,0,0,0,0};
    const bool tileWalkableLookup [55] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    Texture2D texture = LoadTexture("assets/avatar_bopping_glasses_anim_1.1.png");
    tson::Map* map;
    std::vector<Enemy> *enemies;

    void update();
    void draw();
    bool canMoveTo(int x, int y);
};


#endif //RAYLIBSTARTER_PLAYER_H
