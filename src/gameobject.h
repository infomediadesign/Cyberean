//
// Created by lukas on 15.06.2023.
//

#ifndef RAYLIBSTARTER_GAMEOBJECT_H
#define RAYLIBSTARTER_GAMEOBJECT_H

#pragma once
#include "raylib.h"
#include "../Library/tileson.hpp"
#include "player.h"

class gameScene;
class player;
class gameScene;

class gameobject {
public:
    gameobject(int ID, int posX, int posY, player* playerPtr, std::vector<gameobject>& gameObjects, gameScene* gameScenePtr);

    enum{
        button,
        note
    }Type;

    int posX;
    int posY;
    int ID;
    int collected = 0;
    bool touched = true;
    player* playerPtr;
    gameScene* gameScenePtr;

    tson::Map* theMap;
    Rectangle textureSource;
    std::vector<gameobject>* gameObjects;

    void draw(Texture2D texture);
    void update();
};


#endif //RAYLIBSTARTER_GAMEOBJECT_H
