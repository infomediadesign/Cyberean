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
    int cursor;
    Texture2D background = LoadTexture("assets/hauser.png");
    Texture2D windowsoli = LoadTexture("assets/phenster.png");

};


#endif //RAYLIBSTARTER_MAINMENU_H
