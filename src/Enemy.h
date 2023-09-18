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

enum MalwarePart{
    malwareHead,
    malwareBody,
    malwareTail
};
class player;

class gameScene;

class Enemy {
public:
    Enemy(int ID, int posX, int posY, tson::Map *map, std::vector<bool> *covers,
          std::vector<Enemy> *otherEnemies, player *playerPtr);


    EnumType Type;
    MalwarePart malwarePart;
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

    //Malware variables.
    int malwareMoveDelay;
    int malwareMoveCooldown;
    //flag to check if the malware we are updating is already triggered or not.
    bool malwareTriggered = false;

    //Movement variables for boulders and bombs
    int gravityX = 0; //Gravity Vector X
    int gravityY = 0; //Gravity Vector Y
    int consecMoves; // Counts how many tiles an enemy has fallen (mainly for the CryptoMining Bomb)

    //Level 3 Black and White hole variables
    int boulderBornDelay = 240;
    int boulderBornCooldown = 0;

    //Animation related variables and flags
    int animationCounter = 0;
    bool bombWarning = false;
    bool bombExploding = false;
    bool cellExploding = false;

    //Animation Textures
    Texture2D firewallAnim = LoadTexture("assets/animations/enemies/firewall_anim.png");
    Texture2D rogueAntivirusMovingAnim = LoadTexture("assets/animations/enemies/rogue_eyes_move_anim.png");
    //Texture2D rogueAntivirusStillAnim = LoadTexture("assets/animations/enemies/rogue_eyes_still_anim.png"); - Animation halted, cause u can not see the difference.
    Texture2D bombWarningAnim = LoadTexture("assets/animations/enemies/cryptobomb_warning_anim.png");
    Texture2D bombExplodingAnim = LoadTexture("assets/animations/enemies/cryptobomb_explosion_anim.png");
    Texture2D  bombCellExplodingAnim = LoadTexture("assets/animations/enemies/cryptobomb_explosion_single_anim.png");


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

    void setMalwareType(int x, int y, MalwarePart mType);

    ~Enemy() {}

    void bombExplodingFlag(int x, int y, int animCounter);

};

#endif //RAYLIBSTARTER_ENEMY_H
