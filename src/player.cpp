//
// Created by lukas on 15.06.2023.
//

#include "player.h"

void player::update() {
    age++;
    if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
    {
        if (canMoveTo(posX-1,posY))
        posX--;
    }

    if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
    {
        if (canMoveTo(posX,posY-1))
        posY--;
    }

    if(IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
    {
        if (canMoveTo(posX+1,posY))
        posX++;
    }
    if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
    {
        if (canMoveTo(posX,posY+1))
        posY++;
    }
}

void player::draw() {
    DrawTextureRec(texture, Rectangle{(float)age * 32, 0,32, 32}, Vector2{(float)posX * 32, (float)posY * 32}, WHITE);

}

bool player::canMoveTo(int x, int y) {
    int tileData = map->getLayer("collosion")->getData()[x + y * map->getLayer("collosion")->getSize().x];
    return !tileData;
    return false;
}
