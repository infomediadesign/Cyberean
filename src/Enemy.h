//
// Created by lukas on 20.06.2023.
//

#ifndef RAYLIBSTARTER_ENEMY_H
#define RAYLIBSTARTER_ENEMY_H

#pragma once

#include "raylib.h"
#include "../Library/tileson.hpp"
#include "player.h"

enum EnumType{
    boulder,
    firewall,
    rogueAntivirus,
    bomb,
    unknown
};
class player;

class gameScene;

class Enemy {
public:
    Enemy(int ID, int posX, int posY, tson::Map *map, std::vector<bool> *covers,
          std::vector<Enemy> *otherEnemies, player *playerPtr);


    EnumType Type;
    int ID;
    int posX;
    int posY;
    bool isAlive = true;

    //All of the speeds below need to be compacted. (it's ugly like this)
    int gravMoveDelay; //Boulder and Bomb movement speed.
    int gravMoveCooldown;
    int antiVirusMoveDelay; //antiVirus movement speed.
    int antiVirusMoveCooldown;
    int firewallMoveDelay; //Firewall movement speed.
    int firewallMoveCooldown;

    //Movement variables for boulders and bombs
    int gravityX = 0; //Gravity Vector X
    int gravityY = 0; //Gravity Vector Y
    int consecMoves; // Counts how many tiles an enemy has fallen (mainly for the CryptoMining Bomb)

    //Movement variables for rogueAntivirus (counter clockwise)
    enum {
        lookingLeftForWall,
        leftMove,
        downMove,
        rightMove,
        upMove
    } movingStatus;

    tson::Map *theMap;
    Rectangle textureSource;

    bool canMoveTo(int x, int y);

    std::vector<bool> *covers;
    std::vector<Enemy> *otherEnemies;

    void draw(Texture2D texture);

    void update();

    player *playerPtr;

    void switchGravity(int direction);

    void updateGravity();

    int getEnemyID(int x, int y);

    EnumType getEnemyType(int x,int y);

    bool neighborExist90();

    bool neighborExist360();

    void deleteEnemy(int posX, int posY); //kill and reset cell in a certain position.

    void clearEnemyCanvas(); //clear all enemies and boulders from the canvas.

    void explodeBomb(int x, int y);

    void bombRemoveCover(int x, int y);

    ~Enemy() {}

};

#endif //RAYLIBSTARTER_ENEMY_H
