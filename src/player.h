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
    int posX = 0;
    int posY = 0;
    int age = 0;
    int anim = 0;

    Texture2D texture = LoadTexture("assets/mockup_avatar_portal-hop_anim.png");

    void update();
    void draw();
};


#endif //RAYLIBSTARTER_PLAYER_H
