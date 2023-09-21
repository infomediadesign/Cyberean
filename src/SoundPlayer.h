//
// Created by lukas on 21.08.2023.
//

#ifndef RAYLIBSTARTER_SOUNDPLAYER_H
#define RAYLIBSTARTER_SOUNDPLAYER_H

#include "raylib.h"
#include "mastervolumecontroll.h"

class SoundPlayer {
public:
    Sound menucontroll;
    Sound menucontroll2;
    Sound menuenter;
    Sound walk;
    Sound wall;
    Sound note;
    Sound cover;
    Sound button;
    Sound all4notes;
    Sound death;
    Sound cutsceneenter;
    Sound cutscenevoice;
    Sound bomb;
    bool mastersound = true;
    float mastersoundvolume = 1.0f;


    SoundPlayer();
    ~SoundPlayer();
    void menuControll_sound();
    void menuControll2_sound();
    void menuEnter_sound();
    void playerWalk_sound();
    void playerWall_sound();
    void playerNote_sound();
    void playerCover_sound();
    void playerButton_sound();
    void playerDeath_sound();
    void all4Notes();
    void cutsceneenter_sound();
    void cutscenevoice_sound();
    void bomb_sound();
};


#endif //RAYLIBSTARTER_SOUNDPLAYER_H
