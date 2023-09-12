//
// Created by lukas on 09.09.2023.
//

#ifndef RAYLIBSTARTER_STORYMODE_H
#define RAYLIBSTARTER_STORYMODE_H

#include "raylib.h"

#include "config.h"
#include "../Library/tileson.hpp"
#include "masterhead.h"
#include "mainmenu.h"
#include "musicplayer.h"
#include "gameszene.h"
#include "SoundPlayer.h"
#include "mastervolumecontroll.h"
#include "levelselect.h"
#include "credits.h"
#include "cutscene.h"

class storymode {
public:

    MusicPlayer musicPlayer;

    SoundPlayer soundPlayer;

    std::unique_ptr<gameScene> gs = nullptr;

    std::unique_ptr<cutscene> mycutscene;

    globalState state2;

    Texture2D fadeTexture = LoadTexture("assets/screens/storymode/fadeeffect.png");
    float fadeSpeed = 0.5f;
    float fadeAlpha = 0.0f;

    void draw();
    void update(globalState &globalstate);
    storymode();
    void fadein();
    void fadeout();

};


#endif //RAYLIBSTARTER_STORYMODE_H
