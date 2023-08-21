//
// Created by lukas on 21.08.2023.
//

#ifndef RAYLIBSTARTER_SOUNDPLAYER_H
#define RAYLIBSTARTER_SOUNDPLAYER_H

#include "raylib.h"

class SoundPlayer {
public:
    Sound menucontroll;
    Sound menuenter;
    Sound walk;
    Sound wall;
    Sound note;
    Sound cover;
    Sound button;
    Sound all4notes;
    bool mastersoundvolume = true;

    SoundPlayer();
    ~SoundPlayer();
    void menuControll_sound();
    void menuEnter_sound();
    void playerWalk_sound();
    void playerWall_sound();
    void playerNote_sound();
    void playerCover_sound();
    void playerButton_sound();
    void all4Notes();
};


#endif //RAYLIBSTARTER_SOUNDPLAYER_H
