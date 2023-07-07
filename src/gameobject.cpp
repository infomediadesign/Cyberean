//
// Created by lukas on 15.06.2023.
//

#include "gameobject.h"


gameobject::gameobject(int ID, int posX, int posY, player* playerPtr, std::vector<gameobject>& gameObjects, gameScene* gameScenePtr): playerPtr(playerPtr), gameObjects(&gameObjects), gameScenePtr(gameScenePtr) {
    this->posX = posX;
    this->posY = posY;
    this->ID = ID;

    switch(ID)
    {
        case 5:
            textureSource = {0, 32, 32, 32};
            break;
        case 6:
            textureSource = {32, 32, 32, 32};
            break;
    }
}

void gameobject::draw(Texture2D texture) {
    DrawTextureRec(texture, textureSource, Vector2{(float)posX * 32, (float)posY * 32}, WHITE);
}

void gameobject::update() {
    if (playerPtr->posX == posX && playerPtr->posY == posY && ID == 5) {
        for (auto it = gameObjects->begin(); it != gameObjects->end(); ++it) {
            if (&(*it) == this) {
                //gameScenePtr->increaseCollectedObjectsCount();
                gameObjects->erase(it);
                break;
            }
        }
    }
}
