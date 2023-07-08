//
// Created by lukas on 20.06.2023.
//

#include "Enemy.h"

Enemy::Enemy(int ID, int posX, int posY, tson::Map *map, std::vector<bool> *covers,
             std::vector<Enemy> *otherEnemies, player* playerPtr): playerPtr(playerPtr) {
    this->ID = ID;
    this->posX = posX;
    this->posY = posY;
    this->theMap = map;
    this->covers = covers;
    this->otherEnemies = otherEnemies;
    this->Type = boulder; // für nen anderen "Gegner" andere ID übergeben (if needed lol)
    switch(Type)
    {
        default:
            moveDelay = 20; // Boulder Falling Speed (Higher Number = Slower)
            textureSource = {96, 0, 32, 32};
    }
    moveCooldown = moveDelay;
}
    void Enemy::update() { // Boulders Gravity
    moveCooldown--;
    if(canMoveTo(posX + gravityX,posY + gravityY) && moveCooldown <= 0) {
        posY += gravityY;
        posX += gravityX;
        moveCooldown = moveDelay;
    }

}

void Enemy::draw(Texture2D texture) {
    DrawTextureRec(texture, textureSource, Vector2{(float)posX * 32, (float)posY * 32}, WHITE);

}

bool Enemy::canMoveTo(int x, int y) {
    int tileData = theMap->getLayer("Collision")->getData()[x + y * theMap->getSize().x];
    if(tileData != 0){
        return false;
    }
    if ((*covers)[x + y * theMap->getSize().x]) {
        return false;
    }
    for (int i = 0; i < otherEnemies->size(); i++) {
        if ((*otherEnemies)[i].posX == x){
            if ((*otherEnemies)[i].posY == y){
                return false;
            }
        }
    }
    if (x == playerPtr->posX && y == playerPtr->posY) {
        return false;
    }
    return true;
}

void Enemy::switchGravity(int direction) {
    switch (direction % 4){
        case 0:
            gravityX = 0;
            gravityY = 1;
            break;
        case 1:
            gravityX = 1;
            gravityY = 0;
            break;
        case 2:
            gravityY = -1;
            gravityX = 0;
            break;
        case 3:
            gravityX = -1;
            gravityY = 0;
            break;

    }
}