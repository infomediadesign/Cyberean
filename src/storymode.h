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
#include "cutscene2.h"
#include "cutscene3.h"
#include "cutscene4.h"
#include "cutscene5.h"


class storymode {
public:

    MusicPlayer musicPlayer;

    SoundPlayer soundPlayer;

    std::unique_ptr<gameScene> gs = nullptr;

    std::unique_ptr<cutscene> thecutscene = std::make_unique<cutscene>(&soundPlayer, &musicPlayer);
    std::unique_ptr<cutscene2> thecutscene2 = std::make_unique<cutscene2>(&soundPlayer, &musicPlayer);
    std::unique_ptr<cutscene3> thecutscene3 = std::make_unique<cutscene3>(&soundPlayer, &musicPlayer);
    std::unique_ptr<cutscene4> thecutscene4 = std::make_unique<cutscene4>(&soundPlayer, &musicPlayer);
    std::unique_ptr<cutscene5> thecutscene5 = std::make_unique<cutscene5>(&soundPlayer, &musicPlayer);


    globalState state2;

    Texture2D fadeTexture = LoadTexture("assets/screens/storymode/fadeeffect.png");
    float fadeSpeed = 0.5f;
    float fadeAlpha = 0.0f;

    void draw();
    void update(globalState &globalstate);
    void reset();
    storymode();
};


#endif //RAYLIBSTARTER_STORYMODE_H
