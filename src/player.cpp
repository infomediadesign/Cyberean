//
// Created by lukas on 15.06.2023.
//

#include "player.h"

void player::update() {
    age++;
    if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
    {
        posX--;
    }

    if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
    {
        posY--;
    }

    if(IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
    {
        posX++;
    }
    if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
    {
        posY++;
    }
}

void player::draw() {
    DrawTextureRec(texture, Rectangle{(float)age * 32, 0,32, 32}, Vector2{(float)posX * 32, (float)posY * 32}, WHITE);

}
