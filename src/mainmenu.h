//
// Created by lukas on 06.06.2023.
//

#ifndef RAYLIBSTARTER_MAINMENU_H
#define RAYLIBSTARTER_MAINMENU_H

#pragma once

#include "masterhead.h"

class mainmenu {
public:
    void update(globalState &globalState);
    void draw();
    void buttons();
    int cursor = 0;
    Texture2D background = LoadTexture("assets/hauser.png");
    Texture2D windowsoli = LoadTexture("assets/phenster.png");
    Texture2D Exit = LoadTexture("assets/Exit.png");
    Texture2D Exit_markiert = LoadTexture("assets/Exit_markiert.png");
    Texture2D Start = LoadTexture("assets/Start.png");
    Texture2D Start_markiert = LoadTexture("assets/Start_markiert.png");
    Texture2D Muted = LoadTexture("assets/muted.png");
    Texture2D Muted_dunkel = LoadTexture("assets/Muted_dunkel.png");
    Texture2D Unmuted = LoadTexture("unmuted.png");
    Texture2D Unmuted_dunkel = LoadTexture("assets/unmuted_dunkel.png");

};


#endif //RAYLIBSTARTER_MAINMENU_H
