//
// Created by lukas on 20.06.2023.
//

#include "Enemy.h"

Enemy::Enemy(int ID, int posX, int posY, tson::Map *map, std::vector<bool> *covers,
             std::vector<Enemy> *otherEnemies) {
    this->posX = posX;
    this->posY = posY;
    this->theMap = map;
    this->otherEnemies = otherEnemies;
    this->covers = covers;
    this->Type = boulder; // für nen anderen "Gegner" andere ID übergeben (if needed lol)
    switch(Type)
    {
        default:
            moveDelay = 30;
            textureSource = {96, 0, 32, 32};
    }
}

void Enemy::draw(Texture2D texture) {
    DrawTextureRec(texture, textureSource, Vector2{(float)posX * 32, (float)posY * 32}, WHITE);

}

bool Enemy::canMoveTo(int x, int y) {
    int tileData = theMap->getLayer("collision")->getData()[x + y * theMap->getLayer("collision")->getSize().x];
    if(tileData != 0){
        return false;
    }
    return true;
}
