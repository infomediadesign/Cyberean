//
// Created by lukas on 20.06.2023.
//

#include "Enemy.h"
#include "gameszene.h"

Enemy::Enemy(int ID, int posX, int posY, tson::Map *map, std::vector<bool> *covers,
             std::vector<Enemy> *otherEnemies, player *playerPtr) {
    this->ID = ID - 1; //WHY?
    this->posX = posX;
    this->posY = posY;
    this->theMap = map;
    this->covers = covers;
    this->otherEnemies = otherEnemies;
    this->playerPtr = playerPtr;

    //take the texture from the png image based on the id
    textureSource.x = float((this->ID % 4) * 32);
    textureSource.y = float((this->ID / 4) * 32);
    textureSource.width = 32;
    textureSource.height = 32;

    switch (this->ID) {
        case 27:
            this->Type = boulder;
            gravMoveDelay = 20; // Boulder Falling Speed (Higher Number = Slower)
        case 5:
            break; // Firewall
        case 39:
            this->Type = rogueAntivirus;
            movingStatus = leftMove;
            antiVirusMoveDelay = 15; //rogue Antivirus movement speed
            break;
        case 6:
            this->Type = bomb;
            gravMoveDelay = 20; // Same Fall Speed as Data-Chan
            break;
    }
    gravMoveCooldown = gravMoveDelay;
    antiVirusMoveCooldown = antiVirusMoveDelay;
    updateGravity(); //Initialize gravity value
}

void Enemy::update() {
    //Boulder and Bomb Movement Logic
    if (this->Type == boulder || this->Type == bomb) {
        bool bNextEnemiesIsBoulder = false;
        gravMoveCooldown--;
        if (canMoveTo(posX + gravityX, posY + gravityY) && gravMoveCooldown <= 0) {
            posY += gravityY;
            posX += gravityX;
            consecMoves++;
            gravMoveCooldown = gravMoveDelay;
            return;
        } else
            consecMoves = 0;

        //Boulder rolling mechanic
        if (this->Type == boulder) {
            //Check if the enemy next to the boulder (in direction of gravity) is a boulder.
            for (int i = 0; i < otherEnemies->size(); i++)
                if ((*otherEnemies)[i].posX == posX + gravityX && (*otherEnemies)[i].posY == posY + gravityY &&
                    (*otherEnemies)[i].Type == boulder) {
                    bNextEnemiesIsBoulder = true;
                    break;
                }
            //if next enemy is not a boulder -> don't fall next to it.
            if (!bNextEnemiesIsBoulder) return;

            if (gravityX != 0) {
                if (canMoveTo(posX, posY + 1) && canMoveTo(posX + gravityX, posY + 1) && gravMoveCooldown <= 0) {
                    posY += 1;
                    gravMoveCooldown = gravMoveDelay;
                    //Insert animation for data chan (counter clock wise) here:

                } else if (canMoveTo(posX, posY - 1) && canMoveTo(posX + gravityX, posY - 1) && gravMoveCooldown <= 0) {
                    posY -= 1;
                    //Insert animation for data chan (clock wise) here:

                    gravMoveCooldown = gravMoveDelay;
                }

            } else if (gravityY != 0) {
                if (canMoveTo(posX + 1, posY) && canMoveTo(posX + 1, posY + gravityY) && gravMoveCooldown <= 0) {
                    posX += 1;
                    //Insert animation for data chan (clock wise) here:

                    gravMoveCooldown = gravMoveDelay;
                } else if (canMoveTo(posX - 1, posY) && canMoveTo(posX - 1, posY + gravityY) && gravMoveCooldown <= 0) {
                    posX -= 1;
                    //Insert animation for data chan (counter clock wise) here:

                    gravMoveCooldown = gravMoveDelay;
                }
            }
        }
    }
    //Rogue Anti Virus Logic
    if (this->Type == rogueAntivirus) {
        antiVirusMoveCooldown--;
        if (antiVirusMoveCooldown <= 0) {
            switch (movingStatus) {
                case leftMove:
                    if (canMoveTo(posX, posY - 1)) {
                        posY--;
                        movingStatus = upMove;
                    } else if (canMoveTo(posX - 1, posY)) {
                        posX--;
                        movingStatus = leftMove;
                    } else if (canMoveTo(posX, posY + 1)) {
                        posY++;
                        movingStatus = downMove;
                    } else if (canMoveTo(posX + 1, posY)) {
                        posX++;
                        movingStatus = rightMove;
                    }
                    break;
                case downMove:
                    if (canMoveTo(posX - 1, posY)) {
                        posX--;
                        movingStatus = leftMove;
                    } else if (canMoveTo(posX, posY + 1)) {
                        posY++;
                        movingStatus = downMove;
                    } else if (canMoveTo(posX + 1, posY)) {
                        posX++;
                        movingStatus = rightMove;
                    } else if (canMoveTo(posX, posY - 1)) {
                        posY--;
                        movingStatus = upMove;
                    }
                    break;
                case rightMove:
                    if (canMoveTo(posX, posY + 1)) {
                        posY++;
                        movingStatus = downMove;
                    } else if (canMoveTo(posX + 1, posY)) {
                        posX++;
                        movingStatus = rightMove;
                    } else if (canMoveTo(posX, posY - 1)) {
                        posY--;
                        movingStatus = upMove;
                    } else if (canMoveTo(posX - 1, posY)) {
                        posX--;
                        movingStatus = leftMove;
                    }
                    break;
                case upMove:
                    if (canMoveTo(posX + 1, posY)) {
                        posX++;
                        movingStatus = rightMove;
                    } else if (canMoveTo(posX, posY - 1)) {
                        posY--;
                        movingStatus = upMove;
                    } else if (canMoveTo(posX - 1, posY)) {
                        posX--;
                        movingStatus = leftMove;
                    } else if (canMoveTo(posX, posY + 1)) {
                        posY++;
                        movingStatus = downMove;
                    }
                    break;
            }
            antiVirusMoveCooldown = antiVirusMoveDelay;
        }
    }
    //Firewall Logic
    if (this->Type == firewall) {

    }
}

void Enemy::draw(Texture2D texture) {
    DrawTextureRec(texture, textureSource, Vector2{(float) posX * 32, (float) posY * 32}, WHITE);

}

bool Enemy::canMoveTo(int x, int y) { // NOLINT(*-make-member-function-const)
    int gravityVal = theMap->getLayer("Gravity")->getData()[posX + posY * theMap->getSize().x];
    if (gravityVal <= 50 || gravityVal >= 56)
        return false;
    int tileData = theMap->getLayer("Collision")->getData()[x + y * theMap->getSize().x];
    if (tileData != 0) {
        return false;
    }
    if ((*covers)[x + y * theMap->getSize().x]) {
        return false;
    }
    for (int i = 0; i < otherEnemies->size(); i++) {
        if ((*otherEnemies)[i].posX == x) {
            if ((*otherEnemies)[i].posY == y) {
                return false;
            }
        }
    }
    if (x == playerPtr->posX && y == playerPtr->posY) {
        return false;
    }
    return true;
}

//Gravity Direction
void Enemy::switchGravity(int direction) {
    switch (direction) {
        case 0: // Down
            gravityX = 0;
            gravityY = 1;
            break;
        case 1: // Right
            gravityX = 1;
            gravityY = 0;
            break;
        case 2: // Up
            gravityX = 0;
            gravityY = -1;
            break;
        case 3: // Left
            gravityX = -1;
            gravityY = 0;
            break;

    }
}

void Enemy::updateGravity() {
    int gravityVal = theMap->getLayer("Gravity")->getData()[posX + posY * theMap->getSize().x];
    if (gravityVal > 50) {
        switch (gravityVal) {
            case 55:
                if (playerPtr->gravitySwitchStatusRight)
                    switchGravity(3);
                else
                    switchGravity(1); // Right
                break;
            case 52:
                if (playerPtr->gravitySwitchStatusUp)
                    switchGravity(0);
                else
                    switchGravity(2); // Up
                break;
            case 54:
                if (playerPtr->gravitySwitchStatusLeft)
                    switchGravity(1);
                else
                    switchGravity(3); // Left
                break;
            case 53:
            default:
                if (playerPtr->gravitySwitchStatusDown)
                    switchGravity(2);
                else
                    switchGravity(0); // Down
        }
    }
}