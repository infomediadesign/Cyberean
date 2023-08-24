//
// Created by lukas on 21.08.2023.
//

#include "SoundPlayer.h"

void SoundPlayer::menuControll_sound() {
    if(mastersound == true){
        PlaySound(menucontroll);
    }
}

SoundPlayer::SoundPlayer() {
    menucontroll = LoadSound("assets/audio/sfx/menu_button_sound.wav");
    menucontroll2 = LoadSound("assets/audio/sfx/menu_button_sound2.wav");
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
    SetSoundVolume(menuenter, mastersoundvolume);
    PlaySound(menuenter);
}

void SoundPlayer::playerWalk_sound() {
    SetSoundVolume(menuenter, mastersoundvolume);
    PlaySound(walk);
}

void SoundPlayer::playerWall_sound() {
    SetSoundVolume(wall, mastersoundvolume);
    PlaySound(wall);
}

void SoundPlayer::playerCover_sound() {
    SetSoundVolume(cover, mastersoundvolume);
    PlaySound(cover);
}

void SoundPlayer::playerNote_sound() {
    SetSoundVolume(note, mastersoundvolume);
    PlaySound(note);
}

void SoundPlayer::playerButton_sound() {
    SetSoundVolume(button, mastersoundvolume);
    PlaySound(button);
}

void SoundPlayer::all4Notes() {
    SetSoundVolume(all4notes, mastersoundvolume);
    PlaySound(all4notes);
}

void SoundPlayer::menuControll2_sound() {
    SetSoundVolume(menucontroll2, mastersoundvolume);
    PlaySound(menucontroll2);
}
