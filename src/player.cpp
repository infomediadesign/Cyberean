//
// Created by lukas on 15.06.2023.
//

#include "player.h"
#include "thread"
#include "chrono"

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock; // reads system clock

void player::update() {
    age++;
    previousX = posX;
    previousY = posY;
    if (playerDead)
        playerDied();

    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) // Move Left
    {
        checkIfBombShovable(1);
        if (canMoveTo(posX - 1, posY))
            posX--;

    } else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        stepCounterUp = 0;
        stepCounterDown = 0;
        stepCounterRight = 0;
        stepCounterLeft++;
        //sleep_for(50ms); // Not needed, but there cause might be useful.
        if (stepCounterLeft == keyDownDelay) {
            if (canMoveTo(posX - 1, posY))
                posX--;
            stepCounterLeft = 0;
        }
    }

    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))//Move Up
    {
        checkIfBombShovable(3);
        if (canMoveTo(posX, posY - 1))
            posY--;
    } else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        stepCounterUp++;
        stepCounterDown = 0;
        stepCounterRight = 0;
        stepCounterLeft = 0;
        //sleep_for(50ms);
        if (stepCounterUp == keyDownDelay) {
            if (canMoveTo(posX, posY - 1))
                posY--;
            stepCounterUp = 0;
        }
    }

    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) //Move Right
    {
        checkIfBombShovable(0);
        if (canMoveTo(posX + 1, posY))
            posX++;
    } else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        stepCounterUp = 0;
        stepCounterDown = 0;
        stepCounterRight++;
        stepCounterLeft = 0;
        //sleep_for(50ms);
        if (stepCounterRight == keyDownDelay) {
            if (canMoveTo(posX + 1, posY))
                posX++;
            stepCounterRight = 0;
        }
    }
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) //Move Down
    {
        checkIfBombShovable(2);
        if (canMoveTo(posX, posY + 1))
            posY++;
    } else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        stepCounterUp = 0;
        stepCounterDown++;
        stepCounterLeft = 0;
        stepCounterRight = 0;
        //sleep_for(50ms);
        if (stepCounterDown == keyDownDelay) {
            if (canMoveTo(posX, posY + 1))
                posY++;
            stepCounterDown = 0;
        }
    }

    if (previousX != posX) {
        soundplayerPtr->playerWalk_sound();
    }
    if (previousY != posY) {
        soundplayerPtr->playerWalk_sound();
    }
}

void player::draw() {
    if (!vulnerable) {
    }
    DrawTextureRec(texture, Rectangle{age * 32, 0, 32, 32}, Vector2{(float) posX * 32, (float) posY * 32},
                   WHITE);
}

bool player::canMoveTo(int x, int y) {// checks if the player can move to adjacent Tile

    //Collision with None-Walkable Tiles (e.g Wall)
    int tileData = map->getLayer("Collision")->getData()[x + y * map->getLayer("Collision")->getSize().x];
    if (tileData != 0) {
        soundplayerPtr->playerWall_sound();
        return false;
    }
    //Player can walk anywhere when he is in an invulnerable state
    if (!vulnerable) {
        bool EnemyFound = false;
        for (int i = 0; i < enemies->size(); i++) {
            Enemy enemy = (*enemies)[i];
            if (enemy.posX == x && enemy.posY == y)
                         EnemyFound = true;
        }
        if (!EnemyFound) vulnerable = true;


        return true;
    }
    //Collision with enemies
    for (int i = 0; i < enemies->size(); i++) {
        Enemy enemy = (*enemies)[i];
        if (enemy.posX == x && enemy.posY == y) {
            //ADD LOGIC TO KILL THE PLAYER IN THE CASE BELOW!!!
            if (enemy.Type == rogueAntivirus || enemy.Type == firewall || enemy.Type == malware) {
                playerDead = true;
                return true;
            }
            soundplayerPtr->playerWall_sound();
            return false;
        }
    }
    return true;
}

player::player(SoundPlayer *soundPlayer) {
    soundplayerPtr = soundPlayer;
    playerStartPos(masterlevel);
}

void player::playerStartPos(int level) {
    switch (level) {
        case 0:
            posX = 19;
            posY = 12;
            break;
        case 1:
            posX = 19;
            posY = 14;
            break;
        case 2:
            posX = 19;
            posY = 14;
            break;
        case 3:
            posX = 19;
            posY = 14;
            break;
    }
}

void player::checkIfBombShovable(int direction) {
    switch (direction) {
        //Right
        case 0: {
            for (int i = 0; i < enemies->size(); i++) {
                Enemy enemy = (*enemies)[i];
                if (enemy.posX == posX + 1 && enemy.posY == posY && enemy.Type == bomb)
                    if (enemy.canMoveTo(posX + 2, posY)) {
                        (*enemies)[i].posX++;
                        posX++;
                    }

            }
            break;
        }
            //LEFT
        case 1: {
            for (int i = 0; i < enemies->size(); i++) {
                Enemy enemy = (*enemies)[i];
                if (enemy.posX == posX - 1 && enemy.posY == posY && enemy.Type == bomb)
                    if (enemy.canMoveTo(posX - 2, posY)) {
                        (*enemies)[i].posX--;
                        posX--;
                    }
            }
            break;
        }
            //DOWN
        case 2: {
            for (int i = 0; i < enemies->size(); i++) {
                Enemy enemy = (*enemies)[i];
                if (enemy.posX == posX && enemy.posY == posY + 1 && enemy.Type == bomb)
                    if (enemy.canMoveTo(posX, posY + 2)) {
                        (*enemies)[i].posY++;
                        posY++;
                    }

            }
            break;
        }
            //UP
        case 3: {
            for (int i = 0; i < enemies->size(); i++) {
                Enemy enemy = (*enemies)[i];
                if (enemy.posX == posX && enemy.posY == posY - 1 && enemy.Type == bomb)
                    if (enemy.canMoveTo(posX, posY - 2)) {
                        (*enemies)[i].posY--;
                        posY--;
                    }
            }
            break;
        }
    }
}

void player::playerDied() {
    soundplayerPtr->playerDeath_sound();
    if (life == 1) {
        life--;
        playerDead = false;
        //gameOver();
    }
    life--;
    vulnerable = false;
    playerDead = false;
    playerStartPos(masterlevel);
}
