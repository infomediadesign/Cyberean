#include "pausescreen.h"

void pausescreen::update() {

    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        switch (cursor) {
            case 0:
                //soundplayerPtr->menuEnter_sound();
                state = 1; // (1) resume
                break;
            case 1:
                state = 2; // (2) restart
                break;

            case 2:
                state = 3; // (3) mainmenu
                break;

            case 3:
                if(_musicconfig == false){
                    _musicconfig = true;
                }else{
                    _musicconfig = false;
                }
                //soundplayerPtr->menuEnter_sound();

                break;
            case 4:
                if(_soundconfig == false){
                    _soundconfig = true;
                }else{
                    _soundconfig = false;
                }
                //soundplayerPtr->menuEnter_sound();
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
            //soundplayerPtr->menuControll_sound();
        }
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
            cursor--;
            //soundplayerPtr->menuControll2_sound();
        }
        if (cursor < 0) {
            cursor = 4;
        }

        if (cursor > 4) {
            cursor = 0;
        }

        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
            if (cursor == 3) {
                cursor = 4;
                //soundplayerPtr->menuControll_sound();
            } else if (cursor == 4) {
                cursor = 3;
                //soundplayerPtr->menuControll_sound();
            }
        } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
            if (cursor == 3) {
                cursor = 4;
                //soundplayerPtr->menuControll2_sound();
            } else if (cursor == 4) {
                cursor = 3;
                //soundplayerPtr->menuControll2_sound();
            }
        }
    }
}

void pausescreen::draw() {
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(pause,456,100,WHITE);
    //DrawTexture(windowsoli,0,0,WHITE);
}

bool pausescreen::IsMusicMuted() {
    return sound;
}

void pausescreen::buttons() {
    DrawTexture(resume, 334, 400, WHITE);
    DrawTexture(restart, 334, 500, WHITE);
    DrawTexture(mainmenu, 334, 600, WHITE);
    DrawTexture(music,0, 750,WHITE);
    DrawTexture(_sound,650, 750,WHITE);
    /*if (sound == true) {
        DrawTexture(Unmuted_dunkel, 368, 700, WHITE);
    } else {
        DrawTexture(Muted_dunkel, 368, 700, WHITE);
    }*/
    switch (cursor) {
        case 0:
            DrawTexture(resume_markiert, 334, 400, WHITE);
            break;
        case 1:
            DrawTexture(restart_markiert, 334, 500, WHITE);
            break;
        case 2:
            DrawTexture(mainmenu_markiert, 334, 600, WHITE);
            break;
        case 3:
            if(_musicconfig){
                DrawTexture(music_markiert_ausgewaehlt,0, 750,WHITE);
            }else{
                DrawTexture(music_markiert,0, 750,WHITE);
            }
            break;
        case 4:
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

pausescreen::pausescreen() {
}

void pausescreen::musicconfig() {
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        if(masterMusicControl > 0){
            masterMusicControl = masterMusicControl - 0.1;
            //soundplayerPtr->menuControll_sound();
        }
    }

    if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        if(masterMusicControl < 1.0){
            masterMusicControl = masterMusicControl + 0.1;
            //soundplayerPtr->menuControll2_sound();
        }
    }
}

void pausescreen::soundconfig() {
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        if(masterSoundControl > 0){
            masterSoundControl = masterSoundControl - 0.1;
            //soundplayerPtr->menuControll_sound();
        }
    }

    if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        if(masterSoundControl < 1.0){
            masterSoundControl = masterSoundControl + 0.1;
            //soundplayerPtr->menuControll2_sound();
        }
    }
}