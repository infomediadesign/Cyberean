//
// Created by lukas on 04.09.2023.
//

#ifndef RAYLIBSTARTER_CREDITS_H
#define RAYLIBSTARTER_CREDITS_H


#include "masterhead.h"
#include "SoundPlayer.h"
#include "mastervolumecontroll.h"
#include "musicplayer.h"

class credits {
public:

    SoundPlayer *soundplayerPtr;
    MusicPlayer *musicPlayerPtr;

    Texture2D background = LoadTexture("assets/screens/credits_screen/Credits_allnames.png");

    credits(SoundPlayer *soundplayer, MusicPlayer *musicPlayer);

    void update(globalState &globalState);

    void draw();

};


#endif //RAYLIBSTARTER_CREDITS_H
