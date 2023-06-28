//
// Created by lukas on 15.06.2023.
//

#ifndef RAYLIBSTARTER_PLAYER_H
#define RAYLIBSTARTER_PLAYER_H

#include "masterhead.h"
#include "player.h"
#include "gameobject.h"

class player {
public:
    int life = 0;
    int posX = 19;
    int posY = 13;
    int age = 0;
    int anim = 0;
    tson::Map* map;
    const bool tileWalkableLookup[13] = {1,1,0,0,0,0,0,0,0,0,0,0,0};

    Texture2D texture = LoadTexture("assets/mockup_avatar_portal-hop_anim.png");

    void update();
    void draw();
    bool canMoveTo(int x, int y);
};


#endif //RAYLIBSTARTER_PLAYER_H
