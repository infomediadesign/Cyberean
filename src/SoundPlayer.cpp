//
// Created by lukas on 21.08.2023.
//

#include "SoundPlayer.h"

void SoundPlayer::menuControll_sound() {
    if(mastersoundvolume == true){
        PlaySound(menucontroll);
    }
}

SoundPlayer::SoundPlayer() {
    menucontroll = LoadSound("assets/audio/sfx/menu_button_sound.wav");
    menuenter = LoadSound("assets/audio/sfx/menu_enter_sound.wav");
    walk = LoadSound("assets/audio/sfx/walk.wav");
    wall = LoadSound("assets/audio/sfx/wall.wav");
    cover = LoadSound("assets/audio/sfx/walkclear.wav");
    note = LoadSound("assets/audio/sfx/note.wav");
}

SoundPlayer::~SoundPlayer() {
    UnloadSound(menucontroll);
    CloseAudioDevice();
}

void SoundPlayer::menuEnter_sound() {
    if(mastersoundvolume == true){
        PlaySound(menuenter);
    }
}

void SoundPlayer::playerWalk_sound() {
    if(mastersoundvolume == true){
        PlaySound(walk);
    }
}

void SoundPlayer::playerWall_sound() {
    if(mastersoundvolume == true){
        PlaySound(wall);
    }
}

void SoundPlayer::playerCover_sound() {
    if(mastersoundvolume == true){
        PlaySound(cover);
    }
}

void SoundPlayer::playerNote_sound() {
    if(mastersoundvolume == true){
        PlaySound(note);
    }
}
