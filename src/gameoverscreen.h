//
// Created by ashra on 9/6/2023.
//

#ifndef RAYLIBSTARTER_GAMEOVERSCREEN_H
#define RAYLIBSTARTER_GAMEOVERSCREEN_H

#endif //RAYLIBSTARTER_GAMEOVERSCREEN_H

#pragma once

#include "SoundPlayer.h"
#include "mastervolumecontroll.h"

class gameoverscreen {
public:

    int state = 0;

    gameoverscreen();

    void update();

    void draw();

    void buttons();

    //bool IsMusicMuted();

    int cursor = 0;

    bool sound = true;

    SoundPlayer *soundplayerPtr;

    SoundPlayer soundplayer;

    Texture2D background = LoadTexture("assets/screens/pause_screen/background_pause2.png");

    //Change to Game Over Png:
    Texture2D gameover = LoadTexture("assets/screens/game_over_screen/critival_network_error.png");

    //retry button
    Texture2D retry = LoadTexture("assets/screens/game_over_screen/retry_death.png");
    Texture2D retry_markiert = LoadTexture("assets/screens/game_over_screen/retry_selected_death.png");

    Texture2D mainmenu = LoadTexture("assets/screens/game_over_screen/main_menu_death.png");
    Texture2D mainmenu_markiert = LoadTexture("assets/screens/game_over_screen/main_menu_selected_death.png");

    Texture2D exit = LoadTexture("assets/screens/game_over_screen/quit_game_death.png");
    Texture2D exit_markiert = LoadTexture("assets/screens/game_over_screen/quit_game_selected_death.png");

};
