//
// Created by lukas on 04.09.2023.
//

#ifndef RAYLIBSTARTER_CUTSCENE_H
#define RAYLIBSTARTER_CUTSCENE_H

#include "masterhead.h"
#include "SoundPlayer.h"
#include "mastervolumecontroll.h"
#include "musicplayer.h"

class cutscene {
public:

public:
    cutscene(SoundPlayer *soundplayer, MusicPlayer *musicPlayer);

    void update(globalState &globalState);
    void draw();

    SoundPlayer *soundplayerPtr;
    MusicPlayer *musicPlayerPtr;

    Texture2D background;
    int fontSize;
    Color textColor;

    int whichcutscene;
    bool cutsceneFinished;

    std::string fullText;
    std::string fullText2;
    std::string currentText;
    std::string currentFullText;
    int textX, textY;
    int textSpeed;
    int currentTextIndex;
    int textTimer;

    void ResetCutscene();
    void Cutscene_1();

};


#endif //RAYLIBSTARTER_CUTSCENE_H
