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
    button = LoadSound("assets/audio/sfx/button.wav");
    all4notes = LoadSound("assets/audio/sfx/allnotes.wav");
}

SoundPlayer::~SoundPlayer() {
    UnloadSound(menucontroll);
    CloseAudioDevice();
}

void SoundPlayer::menuEnter_sound() {
    if(mastersoundvolume == true){
        SetSoundVolume(menuenter, 1.0f);
        PlaySound(menuenter);
    }
}

void SoundPlayer::playerWalk_sound() {
    if(mastersoundvolume == true){
        SetSoundVolume(menuenter, 1.0f);
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

void SoundPlayer::playerButton_sound() {
    if(mastersoundvolume == true){
        PlaySound(button);
    }
}

void SoundPlayer::all4Notes() {
    if(mastersoundvolume == true){
        PlaySound(all4notes);
    }
}
