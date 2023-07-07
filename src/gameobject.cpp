//
// Created by lukas on 15.06.2023.
//

#include "gameobject.h"

gameobject::gameobject(int ID, int posX, int posY) {
    this->posX = posX;
    this->posY = posY;

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
