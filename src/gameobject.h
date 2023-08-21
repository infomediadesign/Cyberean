//
// Created by lukas on 15.06.2023.
//

#ifndef RAYLIBSTARTER_GAMEOBJECT_H
#define RAYLIBSTARTER_GAMEOBJECT_H

#pragma once

#include "raylib.h"
#include "../Library/tileson.hpp"
#include "player.h"
#include "SoundPlayer.h"

class gameScene;

class player;

class gameobject {
public:
    gameobject(int ID, int posX, int posY, player *playerPtr, std::vector<gameobject> &gameObjects,
               gameScene *gameScenePtr, SoundPlayer *soundplayer);

    enum {
        button, //Gravity switch button
        note //Music notes (collectables)
    } Type;

    int posX;
    int posY;
    int ID;
    int collected = 0;
    bool isActive = false;
    bool playerOnSwitch = false;
    bool switchsoundplayed = false;
    player *playerPtr;
    SoundPlayer *soundplayerPtr;
    gameScene *gameScenePtr;
    Texture2D overlayTexture;

    tson::Map *theMap;
    Rectangle textureSource;
    std::vector<gameobject> *gameObjects;

    void draw(Texture2D texture);

    void update(gameScene &scene);
};


#endif //RAYLIBSTARTER_GAMEOBJECT_H
