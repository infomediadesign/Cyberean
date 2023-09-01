#include "mainmenu.h"

void mainmenu::update(globalState &globalState) {

    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        switch (cursor) {
            case 0:
                soundplayerPtr->menuEnter_sound();
                globalState = levelselection;

                break;
            case 1:
                CloseWindow();
            case 2:
                if(_musicconfig == false){
                    _musicconfig = true;
                }else{
                    _musicconfig = false;
                }
                soundplayerPtr->menuEnter_sound();

                break;
            case 3:
                if(_soundconfig == false){
                    _soundconfig = true;
                }else{
                    _soundconfig = false;
                }
                soundplayerPtr->menuEnter_sound();
                break;
        }
    }


    if(_musicconfig == true){
        musicconfig();
    }

    if(_soundconfig == true){
        soundconfig();
    }

    if(_musicconfig == false && _soundconfig == false){
        if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
            cursor++;
            soundplayerPtr->menuControll_sound();
        }
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
            cursor--;
            soundplayerPtr->menuControll2_sound();
        }
        if (cursor < 0) {
            cursor = 3;
        }

        if (cursor > 3) {
            cursor = 0;
        }

        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
            if (cursor == 2) {
                cursor = 3;
                soundplayerPtr->menuControll_sound();
            } else if (cursor == 3) {
                cursor = 2;
                soundplayerPtr->menuControll_sound();
            }
        } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
            if (cursor == 2) {
                cursor = 3;
                soundplayerPtr->menuControll2_sound();
            } else if (cursor == 3) {
                cursor = 2;
                soundplayerPtr->menuControll2_sound();
            }
        }
    }


}

void mainmenu::draw() {
    DrawTexture(background, 0, 0, WHITE);
    //DrawTexture(windowsoli,0,0,WHITE);
}

bool mainmenu::IsMusicMuted() {
    return sound;
}

void mainmenu::buttons() {
    DrawTexture(Start, 368, 500, WHITE);
    DrawTexture(Exit, 368, 600, WHITE);
    DrawTexture(music,0, 750,WHITE);
    DrawTexture(_sound,650, 750,WHITE);
    /*if (sound == true) {
        DrawTexture(Unmuted_dunkel, 368, 700, WHITE);
    } else {
        DrawTexture(Muted_dunkel, 368, 700, WHITE);
    }*/
    switch (cursor) {
        case 0:
            DrawTexture(Start_markiert, 368, 500, WHITE);
            break;
        case 1:
            DrawTexture(Exit_markiert, 368, 600, WHITE);
            break;
        case 2:
            if(_musicconfig){
                DrawTexture(music_markiert_ausgewaehlt,0, 750,WHITE);
            }else{
                DrawTexture(music_markiert,0, 750,WHITE);
            }
            /*switch (sound) {
                case (true):
                    DrawTexture(Unmuted, 368, 700, WHITE);
                    if (IsKeyPressed(KEY_ENTER) && sound == true) {
                        sound = false;
                    }
                    break;
                case (false):
                    DrawTexture(Muted, 368, 700, WHITE);
                    if (IsKeyPressed(KEY_ENTER) && sound == false) {
                        sound = true;
                    }
                    break;
            }*/
            break;
        case 3:
            if(_soundconfig){
                DrawTexture(sound_markiert_ausgewaehlt,650, 750,WHITE);
            }else{
                DrawTexture(sound_markiert,650, 750,WHITE);
            }
            break;
        default:
            break;
    }
    DrawTexture(strich,342 + (((masterMusicControl * 10) * 2) * 7), 771,WHITE);
    DrawTexture(strich,992 + (((masterSoundControl * 10) * 2) * 7), 771,WHITE);
}

mainmenu::mainmenu(SoundPlayer *soundplayer) {
    soundplayerPtr = soundplayer;
}

void mainmenu::musicconfig() {
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        if(masterMusicControl > 0){
            masterMusicControl = masterMusicControl - 0.1;
            soundplayerPtr->menuControll_sound();
        }
    }

    if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        if(masterMusicControl < 1.0){
            masterMusicControl = masterMusicControl + 0.1;
            soundplayerPtr->menuControll2_sound();
        }
    }
}

void mainmenu::soundconfig() {
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        if(masterSoundControl > 0){
            masterSoundControl = masterSoundControl - 0.1;
            soundplayerPtr->menuControll_sound();
        }
    }

    if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        if(masterSoundControl < 1.0){
            masterSoundControl = masterSoundControl + 0.1;
            soundplayerPtr->menuControll2_sound();
        }
    }
}
