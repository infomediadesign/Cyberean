//
// Created by lukas on 15.06.2023.
//

#ifndef RAYLIBSTARTER_GAMEOBJECT_H
#define RAYLIBSTARTER_GAMEOBJECT_H

#pragma once
class gameScene;
#include "raylib.h"
#include "../Library/tileson.hpp"
#include "player.h"

class gameobject {
public:
    gameobject(int ID, int posX, int posY);

    enum{
        button,
        note
    }Type;

    int posX;
    int posY;
    bool touched = true;

    tson::Map* theMap;
    Rectangle textureSource;

    void draw(Texture2D texture);
    void update();
};


#endif //RAYLIBSTARTER_GAMEOBJECT_H
