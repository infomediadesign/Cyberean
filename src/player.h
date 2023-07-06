//
// Created by lukas on 15.06.2023.
//

#ifndef RAYLIBSTARTER_PLAYER_H
#define RAYLIBSTARTER_PLAYER_H

#pragma once
#include "masterhead.h"
#include "player.h"
#include "gameobject.h"
#include "Enemy.h"

class Enemy;
class gameScene;

class player {
public:
    int life = 0;
    int posX = 19;
    int posY = 13;
    int age = 0;
    int anim = 0;
    gameScene* szene;
    const bool tileWalkableLookup[13] = {1,1,0,0,0,0,0,0,0,0,0,0,0};

    Texture2D texture = LoadTexture("assets/mockup_avatar_portal-hop_anim.png");
    tson::Map* map;
    std::vector<Enemy> *enemies;

    void update();
    void draw();
    bool canMoveTo(int x, int y);
};


#endif //RAYLIBSTARTER_PLAYER_H
