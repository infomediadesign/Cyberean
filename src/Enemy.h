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
    malware,
    blackhole,
    whitehole,
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

    //Boulder and Bomb movement speed.
    int gravMoveDelay;
    int gravMoveCooldown;

    //antiVirus movement speed.
    int antiVirusMoveDelay;
    int antiVirusMoveCooldown;

    //Firewall movement speed.
    int firewallMoveDelay;
    int firewallMoveCooldown;

    //Malware movement speed.
    int malwareMoveDelay;
    int malwareMoveCooldown;

    //Movement variables for boulders and bombs
    int gravityX = 0; //Gravity Vector X
    int gravityY = 0; //Gravity Vector Y
    int consecMoves; // Counts how many tiles an enemy has fallen (mainly for the CryptoMining Bomb)

    //Level 3 Black and White hole variables
    int boulderBornDelay = 240;
    int boulderBornCooldown = 0;

    //Animation related variables
    int animationCounter;

    //Animation Textures
    Texture2D firewallAnim = LoadTexture("assets/animations/enemies/firewall_anim.png");

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

    bool canMoveTo(int x, int y, bool dontKill = false);

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

    bool checkExplosionCell(int x,int y);

    void explodeBomb(int x, int y);

    void bombRemoveCover(int x, int y);

    int getGravityVal(int x, int y);

    ~Enemy() {}

};

#endif //RAYLIBSTARTER_ENEMY_H
