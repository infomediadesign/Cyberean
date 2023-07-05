//
// Created by lukas on 20.06.2023.
//

#ifndef RAYLIBSTARTER_ENEMY_H
#define RAYLIBSTARTER_ENEMY_H

#pragma once
#include "raylib.h"
#include "../Library/tileson.hpp"

class gameScene;

class Enemy {
    public:
    Enemy(int ID, int posX, int posY, tson::Map *map, std::vector<bool> *covers,
          std::vector<Enemy> *otherEnemies);

    enum  {
        boulder,
        firewall,
        bomb
    }Type;

    int posX;
    int posY;
    int moveDelay; //Changing the enemy speed (based on frame)
    int moveCooldown; // remaining time until moving
    bool isAlive = true;
    int gravityX = 0; //Gravity Vector X
    int gravityY = 1; //Gravity Vector Y
    int consecMoves; // Counts how many tiles an enemy has fallen (mainly for the CryptoMining Bomb)
    tson::Map* theMap;
    Rectangle textureSource;

    bool canMoveTo(int x, int y);
    std::vector<bool>*covers;
    std::vector<Enemy>*otherEnemies;
    void draw(Texture2D texture);
    void update();
};
#endif //RAYLIBSTARTER_ENEMY_H
