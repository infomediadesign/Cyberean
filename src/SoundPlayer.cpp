//
// Created by lukas on 21.08.2023.
//

#include "SoundPlayer.h"

void SoundPlayer::menuControll_sound() {
    SetSoundVolume(menucontroll, masterSoundControl);
    PlaySound(menucontroll);
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
    death = LoadSound("assets/audio/sfx/death.wav");
    cutsceneenter = LoadSound("assets/audio/sfx/cutscene_test.wav");
    cutscenevoice = LoadSound("assets/audio/sfx/cutscene_voice.wav");
    bomb = LoadSound("assets/audio/sfx/explosion.wav");
}

SoundPlayer::~SoundPlayer() {
    UnloadSound(menucontroll);
}

void SoundPlayer::menuEnter_sound() {
    SetSoundVolume(menuenter, masterSoundControl);
    PlaySound(menuenter);
}

void SoundPlayer::playerWalk_sound() {
    SetSoundVolume(walk, masterSoundControl * 0.8);
    PlaySound(walk);
}

void SoundPlayer::playerWall_sound() {
    SetSoundVolume(wall, masterSoundControl);
    PlaySound(wall);
}

void SoundPlayer::playerCover_sound() {
    SetSoundVolume(cover, masterSoundControl);
    PlaySound(cover);
}

void SoundPlayer::playerNote_sound() {
    SetSoundVolume(note, masterSoundControl);
    PlaySound(note);
}

void SoundPlayer::playerButton_sound() {
    SetSoundVolume(button, masterSoundControl);
    PlaySound(button);
}

void SoundPlayer::all4Notes() {
    SetSoundVolume(all4notes, masterSoundControl);
    PlaySound(all4notes);
}

void SoundPlayer::menuControll2_sound() {
    SetSoundVolume(menucontroll2, masterSoundControl);
    PlaySound(menucontroll2);
}
void SoundPlayer::playerDeath_sound() {
    SetSoundVolume(death,masterSoundControl);
    PlaySound(death);
}

void SoundPlayer::cutsceneenter_sound() {
    SetSoundVolume(cutsceneenter, masterSoundControl);
    PlaySound(cutsceneenter);
}

void SoundPlayer::cutscenevoice_sound() {
    SetSoundVolume(cutscenevoice, masterSoundControl);
    PlaySound(cutscenevoice);
}

void SoundPlayer::bomb_sound() {
    SetSoundVolume(bomb,masterSoundControl);
    PlaySound(bomb);
}
