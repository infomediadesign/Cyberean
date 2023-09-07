//
// Created by lukas on 20.06.2023.
//

#include "Enemy.h"
#include "gameszene.h"

Enemy::Enemy(int ID, int posX, int posY, tson::Map *map, std::vector<bool> *covers,
             std::vector<Enemy> *otherEnemies, player *playerPtr) {
    this->ID = ID - 1; //because Tiled is a bitch c:
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
        case 3:
            this->Type = boulder;
            gravMoveDelay = 20; // Boulder Falling Speed (Higher Number = Slower)
            break;
        case 7:
            this->Type = firewall;
            if (theMap->getLayer("Firewall Path")->getData()[posX + posY * theMap->getSize().x] == 19)
                firewallMoveDelay = 15; //firewall movement speed (Fastest firewall of size 1x2)
            if (theMap->getLayer("Firewall Path")->getData()[posX + posY * theMap->getSize().x] == 20)
                firewallMoveDelay = 20; //firewall size 1x3
            if (theMap->getLayer("Firewall Path")->getData()[posX + posY * theMap->getSize().x] == 21)
                firewallMoveDelay = 25; //firewall size 1x4
            break;
        case 4:
            this->Type = rogueAntivirus;
            movingStatus = leftMove;
            antiVirusMoveDelay = 15; //rogue Antivirus movement speed
            break;
        case 5:
            this->Type = bomb;
            gravMoveDelay = 20; // Same Fall Speed as Data-Chan
            break;
        default:
            break;
    }
    gravMoveCooldown = gravMoveDelay;
    consecMoves = 0;
    antiVirusMoveCooldown = antiVirusMoveDelay;
    firewallMoveCooldown = firewallMoveDelay;
    updateGravity(); //Initialize gravity value
}

void Enemy::update() {
    //Boulder and Bomb gravity Logic
    if (this->Type == boulder || this->Type == bomb) {
        bool bNextEnemiesIsBoulder = false;
        bool bAboveBoulderIsEnemy = false;
        gravMoveCooldown--;
        if (canMoveTo(posX + gravityX, posY + gravityY) && gravMoveCooldown <= 0) {
            posY += gravityY;
            posX += gravityX;
            consecMoves++;
            gravMoveCooldown = gravMoveDelay;
            //return;
        } else if (this->Type == boulder && consecMoves >= 1 && gravMoveCooldown <= 0) {
            consecMoves = 0;
        } else if (this->Type == bomb && consecMoves == 1 && gravMoveCooldown <= 0) {
            consecMoves = 0;
        } else if (this->Type == bomb && consecMoves >= 2 && gravMoveCooldown <= 0) {
            explodeBomb(posX, posY);
        }

        //Boulder rolling mechanic
        if (this->Type == boulder) {
            //Check if the enemy next to the boulder (in direction of gravity) is a boulder.
            for (auto &otherEnemy: *otherEnemies) {
                if (otherEnemy.posX == posX + gravityX && otherEnemy.posY == posY + gravityY &&
                    otherEnemy.Type == boulder) {
                    bNextEnemiesIsBoulder = true;
                    break;
                }
            }
            //Check if the boulder has an enemy above it of type: boulder , bomb
            for (auto &otherEnemy: *otherEnemies) {
                if (otherEnemy.posX == posX - gravityX && otherEnemy.posY == posY - gravityY &&
                    (otherEnemy.Type == boulder || otherEnemy.Type == bomb)) {
                    bAboveBoulderIsEnemy = true;
                    break;
                }
            }
            //if next enemy is not a boulder -> don't fall next to it.
            //Stacks only when it falls on a boulder.
            if (!bNextEnemiesIsBoulder)
                return;
            //Don't stack if there is a boulder or bomb above you.
            if (bAboveBoulderIsEnemy)
                return;
            if (gravityX != 0) {
                if (canMoveTo(posX, posY + 1) && canMoveTo(posX + gravityX, posY + 1) && gravMoveCooldown <= 0) {
                    if ((getGravityVal(posX, posY + 1) == 15 && !playerPtr->gravitySwitchStatusUp) ||
                        (getGravityVal(posX, posY + 1) == 16 && playerPtr->gravitySwitchStatusDown))
                        return;
                    else {
                        posY += 1;
                        gravMoveCooldown = gravMoveDelay;
                        //Insert animation for data chan (counter clock wise) here:

                    }
                } else if (canMoveTo(posX, posY - 1) && canMoveTo(posX + gravityX, posY - 1) && gravMoveCooldown <= 0) {
                    if ((getGravityVal(posX, posY + 1) == 15 && playerPtr->gravitySwitchStatusUp) ||
                        (getGravityVal(posX, posY + 1) == 16 && !playerPtr->gravitySwitchStatusDown))
                        return;
                    else {
                        posY -= 1;
                        gravMoveCooldown = gravMoveDelay;
                        //Insert animation for data chan (clock wise) here:

                    }
                }
            } else if (gravityY != 0) {
                if (canMoveTo(posX + 1, posY) && canMoveTo(posX + 1, posY + gravityY) && gravMoveCooldown <= 0) {
                    if ((getGravityVal(posX + 1, posY) == 18 && playerPtr->gravitySwitchStatusRight) ||
                        (getGravityVal(posX + 1, posY) == 17 && !playerPtr->gravitySwitchStatusLeft))
                        return;
                    else {
                        posX += 1;
                        gravMoveCooldown = gravMoveDelay;
                        //Insert animation for data chan (clock wise) here:

                    }
                } else if (canMoveTo(posX - 1, posY) && canMoveTo(posX - 1, posY + gravityY) && gravMoveCooldown <= 0) {
                    if ((getGravityVal(posX - 1, posY) == 18 && !playerPtr->gravitySwitchStatusRight) ||
                        (getGravityVal(posX - 1, posY) == 17 && playerPtr->gravitySwitchStatusLeft))
                        return;
                    else {
                        posX -= 1;
                        gravMoveCooldown = gravMoveDelay;
                        //Insert animation for data chan (counter clock wise) here:

                    }
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
                    if (!neighborExist360()) {
                        posX--;
                        movingStatus = lookingLeftForWall;
                    } else if (canMoveTo(posX, posY - 1)) {
                        if (!canMoveTo(posX + 1, posY - 1)) {
                            posY--;
                            movingStatus = upMove;
                        } else if (canMoveTo(posX, posY + 1)) {
                            if (!canMoveTo(posX + 1, posY + 1)) {
                                posY++;
                                movingStatus = downMove;
                            } else
                                movingStatus = lookingLeftForWall;
                        } else
                            movingStatus = lookingLeftForWall;
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
                    if (!neighborExist360()) {
                        posX--;
                        movingStatus = lookingLeftForWall;
                    } else if (canMoveTo(posX - 1, posY)) {
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
                    if (!neighborExist360()) {
                        posX--;
                        movingStatus = lookingLeftForWall;
                    } else if (canMoveTo(posX, posY + 1)) {
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
                    if (!neighborExist360()) {
                        posX--;
                        movingStatus = lookingLeftForWall;
                    } else if (canMoveTo(posX + 1, posY)) {
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
                case lookingLeftForWall:
                    if (!canMoveTo(posX - 1, posY)) {
                        if (canMoveTo(posX, posY + 1)) {
                            posY++;
                            movingStatus = downMove;
                        } else
                            movingStatus = downMove;
                    } else
                        posX--;
                    break;
            }
            antiVirusMoveCooldown = antiVirusMoveDelay;
        }
    }
    //Firewall Logic
    if (this->Type == firewall) {
        firewallMoveCooldown--;
        if (firewallMoveCooldown <= 0) {
            switch (movingStatus) {
                case rightMove:
                    if (theMap->getLayer("Firewall Path")->getData()[posX + 1 + posY * theMap->getSize().x] != 0)
                        posX++;
                    else {
                        posX--;
                        movingStatus = leftMove;
                    }
                    break;
                case leftMove:
                    if (theMap->getLayer("Firewall Path")->getData()[posX - 1 + posY * theMap->getSize().x] != 0)
                        posX--;
                    else {
                        posX++;
                        movingStatus = rightMove;
                    }
                    break;
                case upMove:
                    if (theMap->getLayer("Firewall Path")->getData()[posX + (posY + 1) * theMap->getSize().x] != 0)
                        posY++;
                    else {
                        posY--;
                        movingStatus = downMove;
                    }
                    break;
                case downMove:
                    if (theMap->getLayer("Firewall Path")->getData()[posX + (posY - 1) * theMap->getSize().x] != 0)
                        posY--;
                    else {
                        posY++;
                        movingStatus = upMove;
                    }
                    break;
            }
            firewallMoveCooldown = firewallMoveDelay;
            if (posX == playerPtr->posX && posY == playerPtr->posY && playerPtr->vulnerable)
                playerPtr->playerDead = true;
        }
    }
}

void Enemy::draw(Texture2D texture) {
    DrawTextureRec(texture, textureSource, Vector2{(float) posX * 32, (float) posY * 32}, WHITE);

}

bool Enemy::canMoveTo(int x, int y) {
    int gravityVal = theMap->getLayer("Gravity")->getData()[posX + posY * theMap->getSize().x];
    if (gravityVal <= 14 || gravityVal >= 19)
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
    //Enemy-> player and enemy contact:
    if (this->Type == rogueAntivirus) {
        if (x == playerPtr->posX && y == playerPtr->posY && playerPtr->vulnerable) {
            playerPtr->playerDead = true;
            return true;
        }
        for (int i = 0; i < otherEnemies->size(); i++) {
            if ((*otherEnemies)[i].posX == x) {
                if ((*otherEnemies)[i].posY == y && (*otherEnemies)[i].Type != firewall) {
                    return false;
                }
            }
        }
        return true;
    }
    if (this->Type == boulder) {
        if (x == playerPtr->posX && y == playerPtr->posY) {
            if (this->consecMoves >= 1 && playerPtr->vulnerable) {
                playerPtr->playerDead = true;
                return true;
            } else return false;
        }
        for (int i = 0; i < otherEnemies->size(); i++) {
            if ((*otherEnemies)[i].posX == x) {
                if ((*otherEnemies)[i].posY == y && (*otherEnemies)[i].Type != firewall) {
                    return false;
                }
            }
        }
        return true;
    }
    if (this->Type == bomb) {
        for (int i = 0; i < otherEnemies->size(); i++) {
            if ((*otherEnemies)[i].posX == x) {
                if ((*otherEnemies)[i].posY == y && (*otherEnemies)[i].Type != firewall) {
                    return false;
                }
            }
        }
    }
    if (x == playerPtr->posX && y == playerPtr->posY)
        return false;
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
    if (gravityVal > 14) {
        switch (gravityVal) {
            case 18:
                if (playerPtr->gravitySwitchStatusRight)
                    switchGravity(3);
                else
                    switchGravity(1); // Right
                break;
            case 15:
                if (playerPtr->gravitySwitchStatusUp)
                    switchGravity(0);
                else
                    switchGravity(2); // Up
                break;
            case 17:
                if (playerPtr->gravitySwitchStatusLeft)
                    switchGravity(1);
                else
                    switchGravity(3); // Left
                break;
            case 16:
            default:
                if (playerPtr->gravitySwitchStatusDown)
                    switchGravity(2);
                else
                    switchGravity(0); // Down
        }
    }
}

//Returns true if enemy can move Up && Down && Left && Right.
bool Enemy::neighborExist90() {
    if (canMoveTo(posX - 1, posY) &&
        canMoveTo(posX + 1, posY) &&
        canMoveTo(posX, posY + 1) &&
        canMoveTo(posX, posY - 1))
        return false;
    return true;
}

bool Enemy::neighborExist360() {
    if (canMoveTo(posX - 1, posY) &&
        canMoveTo(posX + 1, posY) &&
        canMoveTo(posX, posY + 1) &&
        canMoveTo(posX, posY - 1) &&
        canMoveTo(posX - 1, posY - 1) &&
        canMoveTo(posX + 1, posY + 1) &&
        canMoveTo(posX - 1, posY + 1) &&
        canMoveTo(posX + 1, posY - 1))
        return false;
    return true;
}

int Enemy::getEnemyID(int x, int y) {
    int nID = 0;
    for (int i = 0; i < otherEnemies->size(); i++) {
        if ((*otherEnemies)[i].posX == x) {
            if ((*otherEnemies)[i].posY == y) {
                nID = (*otherEnemies)[i].ID;
            }
        }
    }
    return nID;
}

EnumType Enemy::getEnemyType(int x, int y) {

    for (int i = 0; i < otherEnemies->size(); i++) {
        if ((*otherEnemies)[i].posX == x) {
            if ((*otherEnemies)[i].posY == y) {
                return (*otherEnemies)[i].Type;
            }
        }
    }
    return unknown;
}

void Enemy::deleteEnemy(int x, int y) {
    for (int i = 0; i < otherEnemies->size(); i++) {
        if ((*otherEnemies)[i].posX == x) {
            if ((*otherEnemies)[i].posY == y && (*otherEnemies)[i].Type != firewall)
                otherEnemies->erase(otherEnemies->begin() + i);
        }
    }
}

void Enemy::bombRemoveCover(int x, int y) {
    int coverIndex = x + y * playerPtr->map->getSize().x;
    if ((*covers)[coverIndex]) {
        (*covers)[coverIndex] = false;
    }
}

bool Enemy::checkExplosionCell(int x, int y) {
    if (playerPtr->posX == x && playerPtr->posY == y && playerPtr->vulnerable) {
        playerPtr->playerDead = true;
        return true;
    }
    if (getEnemyType(x, y) == bomb)
        explodeBomb(x, y); //recursive check and detonations of bombs affected by other bombs
    else deleteEnemy(x, y);
    bombRemoveCover(x, y); //remove covers affected by the bomb
    return false;
}

void Enemy::explodeBomb(int x, int y) {
    //delete enemies around the bomb
    //   ___________
    //  |_X_|_X_|_X_|
    //  |_X_|_O_|_X_|
    //  |_X_|_X_|_X_|

    deleteEnemy(x, y); //Bomb Location

    if (checkExplosionCell(x - 1, y - 1))
        return;
    if (checkExplosionCell(x - 1, y))
        return;
    if (checkExplosionCell(x - 1, y + 1))
        return;
    if (checkExplosionCell(x, y - 1))
        return;
    if (checkExplosionCell(x, y + 1))
        return;
    if (checkExplosionCell(x + 1, y - 1))
        return;
    if (checkExplosionCell(x + 1, y))
        return;
    if (checkExplosionCell(x + 1, y + 1))
        return;
}

int Enemy::getGravityVal(int x, int y) {
    return theMap->getLayer("Gravity")->getData()[x + y * theMap->getSize().x];
}