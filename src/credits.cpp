//
// Created by lukas on 04.09.2023.
//

#include "credits.h"

credits::credits(SoundPlayer *soundplayer, MusicPlayer *musicPlayer) {
    soundplayerPtr = soundplayer;
    musicPlayerPtr = musicPlayer;
}

void credits::update(globalState &globalState) {
    musicPlayerPtr->PlayMusic(MusicState::credits);
    musicPlayerPtr->SetMusicVolume(masterMusicControl);
    if(IsKeyPressed(KEY_ESCAPE)){
        soundplayerPtr->menuEnter_sound();
        musicPlayerPtr->StopMusic();
        globalState = mainMenu;
    }
}

void credits::draw() {
    DrawTexture(background,0,0,WHITE);
}
