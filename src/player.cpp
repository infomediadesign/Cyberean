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

    if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && !playerDead) // Move Left
    {
        checkIfBombShovable(1);
        if (canMoveTo(posX - 1, posY))
            posX--;

    } else if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) && !playerDead) {
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

    if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && !playerDead)//Move Up
    {
        checkIfBombShovable(3);
        if (canMoveTo(posX, posY - 1))
            posY--;
    } else if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && !playerDead) {
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

    if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && !playerDead) //Move Right
    {
        checkIfBombShovable(0);
        if (canMoveTo(posX + 1, posY))
            posX++;
    } else if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && !playerDead) {
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
    if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && !playerDead) //Move Down
    {
        checkIfBombShovable(2);
        if (canMoveTo(posX, posY + 1))
            posY++;
    } else if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) && !playerDead) {
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
    switch (deathCause) {

        case deadByFirewall:
            playerDeathAnim = playerDeathAnimMelt;
            break;

        case deadByMalware:
            playerDeathAnim = playerDeathAnimGrid;
            break;

        case deadByBomb:
            playerDeathAnim = playerDeathAnimAsh;
            break;

        case deadByAntivirus:
            playerDeathAnim = playerDeathAnimSuck;
            break;

        case deadByBoulder:
            playerDeathAnim = playerDeathAnimMelt;
            break;

        default:
            break;
    }

    //Blink if player is invulnerable
    if (playerDead) {
        deathAnimationCounter++;
        if (deathAnimationCounter > 70) { //Divided by 70 to slow the death animation
            playerDied();
            playerDead = false;
            if (life >= 1)
                playerStartPos(masterlevel);
            deathAnimationCounter = 0;
        } else
            DrawTextureRec(playerDeathAnim, Rectangle{(float) (deathAnimationCounter / 10) * 32, 0, 32, 32},
                           Vector2{(float) posX * 32, (float) posY * 32},
                           WHITE);
    } else if (life <= 0) {
        DrawTextureRec(playerDeathAnim, Rectangle{7 * 32, 0, 32, 32}, Vector2{(float) posX * 32, (float) posY * 32},
                       WHITE);
    } else if (!vulnerable) {
        blinkCounter++;
        if (blinkCounter == blinkDuration)
            blinkCounter = 0;
        if (blinkCounter < blinkDuration / 2)
            DrawTextureRec(texture, Rectangle{age * 32, 0, 32, 32}, Vector2{(float) posX * 32, (float) posY * 32},
                           WHITE);
    } else
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
            switch (enemy.Type) {
                case rogueAntivirus: {
                    playerDead = true;
                    deathCause = deadByAntivirus;
                    return true;
                    break;
                }
                case firewall: {
                    playerDead = true;
                    deathCause = deadByFirewall;
                    return true;
                    break;
                }
                case malware: {
                    playerDead = true;
                    deathCause = deadByMalware;
                    return true;
                    break;
                }
                default:
                    break;
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
            posX = 18;
            posY = 12;
            break;
        case 2:
            posX = 14;
            posY = 13;
            break;
        case 3:
            posX = 16;
            posY = 15;
            break;
    }
}

void player::checkIfBombShovable(int direction) {
    switch (direction) {
        //Right
        case 0: {
            for (int i = 0; i < enemies->size(); i++) {
                if ((*enemies)[i].posX == posX + 1 && (*enemies)[i].posY == posY && (*enemies)[i].Type == bomb)
                    if ((*enemies)[i].canMoveTo(posX + 2, posY)) {
                        (*enemies)[i].gravMoveCooldown = (*enemies)[i].gravMoveDelay;
                        (*enemies)[i].posX++;
                        posX++;
                    }

            }
            break;
        }
            //LEFT
        case 1: {
            for (int i = 0; i < enemies->size(); i++) {
                if ((*enemies)[i].posX == posX - 1 && (*enemies)[i].posY == posY && (*enemies)[i].Type == bomb)
                    if ((*enemies)[i].canMoveTo(posX - 2, posY)) {
                        (*enemies)[i].gravMoveCooldown = (*enemies)[i].gravMoveDelay;
                        (*enemies)[i].posX--;
                        posX--;
                    }
            }
            break;
        }
            //DOWN
        case 2: {
            for (int i = 0; i < enemies->size(); i++) {
                if ((*enemies)[i].posX == posX && (*enemies)[i].posY == posY + 1 && (*enemies)[i].Type == bomb)
                    if ((*enemies)[i].canMoveTo(posX, posY + 2)) {
                        (*enemies)[i].gravMoveCooldown = (*enemies)[i].gravMoveDelay;
                        (*enemies)[i].posY++;
                        posY++;
                    }

            }
            break;
        }
            //UP
        case 3: {
            for (int i = 0; i < enemies->size(); i++) {
                if ((*enemies)[i].posX == posX && (*enemies)[i].posY == posY - 1 && (*enemies)[i].Type == bomb)
                    if ((*enemies)[i].canMoveTo(posX, posY - 2)) {
                        (*enemies)[i].gravMoveCooldown = (*enemies)[i].gravMoveDelay;
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
        gameOver = true;
    } else {
        life--;
        vulnerable = false;
    }
    //playerDead = false;
    //playerStartPos(masterlevel);
}
