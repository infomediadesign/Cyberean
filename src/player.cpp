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

    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) // Move Left
    {
        if (canMoveTo(posX - 1, posY))
            posX--;

    } else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
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

    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) //Move Up
    {
        if (canMoveTo(posX, posY - 1))
            posY--;
    } else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
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

    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) //Move Right
    {
        if (canMoveTo(posX + 1, posY))
            posX++;
    } else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
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
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) //Move Down
    {
        if (canMoveTo(posX, posY + 1))
            posY++;
    } else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
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
}

void player::draw() {
    DrawTextureRec(texture, Rectangle{(float) age * 32, 0, 32, 32}, Vector2{(float) posX * 32, (float) posY * 32},
                   WHITE);

}

bool player::canMoveTo(int x, int y) {// checks if the player can move to adjacent Tile

    //Collision with None-Walkable Tiles (e.g Wall)
    int tileData = map->getLayer("Collision")->getData()[x + y * map->getLayer("Collision")->getSize().x];
    if (tileData != 0) {
        return false;
    }
    //Collision with enemies
    for (int i = 0; i < enemies->size(); i++) {
        Enemy enemy = (*enemies)[i];
        if (enemy.posX == x && enemy.posY == y) {
            return false;
        }
    }
    return true;
}
