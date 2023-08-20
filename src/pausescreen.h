//
// Created by selina on 05/07/2023.
//

#ifndef RAYLIBSTARTER_PAUSESCREEN_H
#define RAYLIBSTARTER_PAUSESCREEN_H

#include "masterhead.h"


class pausescreen {
public:
    void update(globalState &globalState);

    void draw();

    void buttons();

    bool IsMusicMuted();

    int cursor = 0;
    bool sound = true;

    Texture2D Exit = LoadTexture("assets/screens/menu_screen/Exit.png");
    Texture2D Exit_markiert = LoadTexture("assets/screens/menu_screen/Exit_markiert.png");
    Texture2D Start = LoadTexture("assets/screens/menu_screen/Start.png");
    Texture2D Start_markiert = LoadTexture("assets/screens/menu_screen/Start_markiert.png");
    Texture2D Muted = LoadTexture("assets/screens/menu_screen/muted.png");
    Texture2D Muted_dunkel = LoadTexture("assets/screens/menu_screen/Muted_dunkel.png");
    Texture2D Unmuted = LoadTexture("assets/screens/menu_screen/unmuted.png");
    Texture2D Unmuted_dunkel = LoadTexture("assets/screens/menu_screen/unmuted_dunkel.png");
};


#endif //RAYLIBSTARTER_PAUSESCREEN_H
