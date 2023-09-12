//
// Created by lukas on 01.09.2023.
//

#ifndef RAYLIBSTARTER_LEVELSELECT_H
#define RAYLIBSTARTER_LEVELSELECT_H

#pragma once

#include "masterhead.h"
#include "SoundPlayer.h"
#include "mastervolumecontroll.h"
#include "musicplayer.h"

class levelselect {
public:
    int cursor = 0;

    int level = 0;

    int counter = 0;
    int currentnote = 0;

    bool song1 = false;
    bool song2 = false;
    bool song3 = false;
    bool song4 = false;

    SoundPlayer *soundplayerPtr;
    MusicPlayer *musicPlayerPtr;

    bool fadeout = false;
    float alpha = 0.0f;
    float fadeSpeed = 1.0f;
    Texture2D fadeTexture = LoadTexture("assets/screens/storymode/fadeeffect.png");

    void update(globalState &globalState);
    void draw();
    levelselect(SoundPlayer *soundplayer, MusicPlayer *musicPlayer);

    Texture2D levelselect1 = LoadTexture("assets/screens/level_select_screen/level_select_1.png");
    Texture2D levelselect2 = LoadTexture("assets/screens/level_select_screen/level_select_2.png");
    Texture2D levelselect3 = LoadTexture("assets/screens/level_select_screen/level_select_3.png");
    Texture2D levelselect4 = LoadTexture("assets/screens/level_select_screen/level_select_4.png");
    Texture2D levelselect5 = LoadTexture("assets/screens/level_select_screen/level_select_5.png");
    Texture2D levelselect6 = LoadTexture("assets/screens/level_select_screen/level_select_6.png");
    Texture2D levelselect7 = LoadTexture("assets/screens/level_select_screen/level_select_7.png");
    Texture2D levelselect8 = LoadTexture("assets/screens/level_select_screen/level_select_8.png");

    Texture2D note1 = LoadTexture("assets/screens/level_select_screen/notes_1.png");
    Texture2D note2 = LoadTexture("assets/screens/level_select_screen/notes_2.png");


};


#endif //RAYLIBSTARTER_LEVELSELECT_H
