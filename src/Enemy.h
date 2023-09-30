//
// Created by lukas on 20.06.2023.
//

#ifndef RAYLIBSTARTER_ENEMY_H
#define RAYLIBSTARTER_ENEMY_H

#pragma once

#include "raylib.h"
#include "../Library/tileson.hpp"
#include "player.h"
#include "SoundPlayer.h"
#include "TextureManager.h"

enum EnumType{
    boulder,
    firewall,
    rogueAntivirus,
    bomb,
    malware,
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
    bool soundbomb = false;
    int counter = 0;

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
    int malwareLifeCounter;
    bool malwareTriggered;
    bool malwareExploded;
    bool malwareDead = false;
    Enemy *malwareHeadPtr;
    Enemy *malwareBodyPtr;
    Enemy *malwareTailPtr;

    int boulderBornDelay = 240;
    int boulderBornCooldown = 0;


    //Movement variables for boulders and bombs
    int gravityX = 0; //Gravity Vector X
    int gravityY = 0; //Gravity Vector Y
    int consecMoves; // Counts how many tiles an enemy has fallen (mainly for the CryptoMining Bomb)

    //Animation related variables and flags
    int animationCounter = 0;
    bool bombWarning = false;
    bool bombExploding = false;
    bool cellExploding = false;

    //Firewall Animation Textures
    Texture2D firewallAnim = TextureManager::firewallAnim;
    Texture2D rogueAntivirusMovingAnim = TextureManager::rogueAntivirusMovingAnim;
    Texture2D bombWarningAnim = TextureManager::bombWarningAnim;
    Texture2D bombExplodingAnim = TextureManager::bombExplodingAnim;
    Texture2D  bombCellExplodingAnim = TextureManager::bombCellExplodingAnim;
    Texture2D malwareAliveAnim = TextureManager::malwareAliveAnim;
    Texture2D  malwareDeathAnim = TextureManager::malwareDeathAnim;
    Texture2D  malwareDetonationAnim = TextureManager::malwareDetonationAnim;


    //Boulder Animation Texures
    //Texture2D  boulderEyesClosing = LoadTexture("assets/data-chan/animations/anim_orange_data-chan_eyes_close.png");
    //Texture2D  boulderEyesOpening = LoadTexture("assets/data-chan/animations/anim_orange_data-chan_eyes_open.png");
    //Texture2D  boulderClockWise = LoadTexture("assets/data-chan/animations/orange_data-chan_tumbling_cw.png");
    //Texture2D  boulderCounterClockWise = LoadTexture("assets/data-chan/animations/orange_data-chan_tumbling_ccw.png");



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

    //void setMalwareType(int x, int y, MalwarePart mType);

    void creatMalware(int xHead, int yHead, int xBody, int yBody, int xTail, int yTail);

    ~Enemy() {}

    void bombExplodingFlag(int x, int y, int animCounter);

    bool shouldExplode(int x, int y);

    //SoundPlayer soundPlayer;

    void spawnBoulder(int x, int y);

};

#endif //RAYLIBSTARTER_ENEMY_H
