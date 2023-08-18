//
// Created by lukas on 20.06.2023.
//

#ifndef RAYLIBSTARTER_ENEMY_H
#define RAYLIBSTARTER_ENEMY_H

#pragma once

#include "raylib.h"
#include "../Library/tileson.hpp"
#include "player.h"

class player;

class gameScene;

class Enemy {
public:
    Enemy(int ID, int posX, int posY, tson::Map *map, std::vector<bool> *covers,
          std::vector<Enemy> *otherEnemies, player *playerPtr);

    enum {
        boulder,
        firewall,
        bomb
    } Type;

    int ID;
    int posX;
    int posY;
    int moveDelay; //Changing the enemy speed (based on frame)
    int moveCooldown; // remaining time until moving
    bool isAlive = true;
    int gravityX = 0; //Gravity Vector X
    int gravityY = 0; //Gravity Vector Y
    int consecMoves; // Counts how many tiles an enemy has fallen (mainly for the CryptoMining Bomb)

    tson::Map *theMap;
    Rectangle textureSource;

    bool canMoveTo(int x, int y);

    std::vector<bool> *covers;
    std::vector<Enemy> *otherEnemies;

    void draw(Texture2D texture);

    void update();

    player *playerPtr;

    void switchGravity(int direction); //Needs to be updated.
    void updateGravity();


};

#endif //RAYLIBSTARTER_ENEMY_H
