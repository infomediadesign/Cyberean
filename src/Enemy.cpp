//
// Created by lukas on 20.06.2023.
//

#include "Enemy.h"

Enemy::Enemy(int ID, int posX, int posY, gameSzene *szene) {
    this->posX = posX;
    this->posY = posY;
    this->theMap = szene;
    this->Type = boulder;
    // für nen anderen "Gegner" andere ID übergeben (if needed lol)

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
