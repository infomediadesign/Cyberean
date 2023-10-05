#include "pausescreen.h"

void pausescreen::update() {

    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        soundplayer.menuEnter_sound();
        switch (cursor) {
            case 0:
                state = 1; // (1) resume
                break;
            case 1:
                state = 2; // (2) restart
                break;

            case 2:
                state = 3; // (3) mainmenu
                break;

            case 3:
                CloseWindow();
                break;
            case 4:
                if (_musicconfig == false) {
                    _musicconfig = true;
                } else {
                    _musicconfig = false;
                }
                break;
            case 5:
                if (_soundconfig == false) {
                    _soundconfig = true;
                } else {
                    _soundconfig = false;
                }
                break;
        }
    }


    if (_musicconfig == true) {
        musicconfig();
    }

    if (_soundconfig == true) {
        soundconfig();
    }

    /*if(_musicconfig == false && _soundconfig == false){
        if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
            cursor++;
            //soundplayerPtr->menuControll_sound();
        }
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
            cursor--;
            //soundplayerPtr->menuControll2_sound();
        }
        if (cursor < 0) {
            cursor = 5;
        }

        if (cursor > 5) {
            cursor = 0;
        }

        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
            if (cursor == 4) {
                cursor = 5;
                //soundplayerPtr->menuControll_sound();
            } else if (cursor == 5) {
                cursor = 4;
                //soundplayerPtr->menuControll_sound();
            }
        } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
            if (cursor == 4) {
                cursor = 5;
                //soundplayerPtr->menuControll2_sound();
            } else if (cursor == 5) {
                cursor = 4;
                //soundplayerPtr->menuControll2_sound();
            }
        }
    }
}*/
    if (_musicconfig == false && _soundconfig == false) {
        if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
            if (cursor == 3) {
                cursor = 3;
            } else if (cursor == 4 || cursor == 5) {

            } else {
                cursor++;
            }
            soundplayer.menuControll_sound();
        }
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
            soundplayer.menuControll2_sound();
            if (cursor == 5 || cursor == 4) {
                cursor = 3;
            } else {
                cursor--;
            }
        }
        if (cursor < 0) {
            cursor = 0;
        }
        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
            soundplayer.menuControll_sound();

            if (cursor == 0 || cursor == 1 || cursor == 2 || cursor == 3) {
                cursor = 4;
            } else if (cursor == 4) {
                cursor = 5;
            } else if (cursor == 5) {
                cursor = 3;
            }
        } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
            soundplayer.menuControll2_sound();

            if (cursor == 0 || cursor == 1 || cursor == 2 || cursor == 3) {
                cursor = 5;
            } else if (cursor == 4) {
                cursor = 3;
            } else if (cursor == 5) {
                cursor = 4;
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
    DrawTexture(resume, 456, 400, WHITE);
    DrawTexture(restart, 456, 500, WHITE);
    DrawTexture(mainmenu, 456, 600, WHITE);
    DrawTexture(music,10 + k, 829,WHITE);
    DrawTexture(_sound,894 + k, 829,WHITE);
    DrawTexture(quit_game,456,700,WHITE);

    if (masterMusicControl <= 0.05) {
        DrawTexture(vol_0, 5 + k, 876, WHITE);
    } else if (masterMusicControl > 0.05 && masterMusicControl <= 0.15) {
        DrawTexture(vol_1, 5 + k, 876, WHITE);
    } else if (masterMusicControl > 0.15 && masterMusicControl <= 0.25) {
        DrawTexture(vol_2, 5 + k, 876, WHITE);
    } else if (masterMusicControl > 0.25 && masterMusicControl <= 0.35) {
        DrawTexture(vol_3, 5 + k, 876, WHITE);
    } else if (masterMusicControl > 0.35 && masterMusicControl <= 0.45) {
        DrawTexture(vol_4, 5 + k, 876, WHITE);
    } else if (masterMusicControl > 0.45 && masterMusicControl <= 0.55) {
        DrawTexture(vol_5, 5 + k, 876, WHITE);
    } else if (masterMusicControl > 0.55 && masterMusicControl <= 0.65) {
        DrawTexture(vol_6, 5 + k, 876, WHITE);
    } else if (masterMusicControl > 0.65 && masterMusicControl <= 0.75) {
        DrawTexture(vol_7, 5 + k, 876, WHITE);
    } else if (masterMusicControl > 0.75 && masterMusicControl <= 0.85) {
        DrawTexture(vol_8, 5 + k, 876, WHITE);
    } else if (masterMusicControl > 0.85 && masterMusicControl <= 0.95) {
        DrawTexture(vol_9, 5 + k, 876, WHITE);
    } else if (masterMusicControl > 0.95 && masterMusicControl <= 1.05) {
        DrawTexture(vol_10, 5 + k, 876, WHITE);
    } else {

    }

    if (masterSoundControl <= 0.05) {
        DrawTexture(vol_0, 885 + k, 876, WHITE);
    } else if (masterSoundControl > 0.05 && masterSoundControl <= 0.15) {
        DrawTexture(vol_1, 885 + k, 876, WHITE);
    } else if (masterSoundControl > 0.15 && masterSoundControl <= 0.25) {
        DrawTexture(vol_2, 885 + k, 876, WHITE);
    } else if (masterSoundControl > 0.25 && masterSoundControl <= 0.35) {
        DrawTexture(vol_3, 885 + k, 876, WHITE);
    } else if (masterSoundControl > 0.35 && masterSoundControl <= 0.45) {
        DrawTexture(vol_4, 885 + k, 876, WHITE);
    } else if (masterSoundControl > 0.45 && masterSoundControl <= 0.55) {
        DrawTexture(vol_5, 885 + k, 876, WHITE);
    } else if (masterSoundControl > 0.55 && masterSoundControl <= 0.65) {
        DrawTexture(vol_6, 885 + k, 876, WHITE);
    } else if (masterSoundControl > 0.65 && masterSoundControl <= 0.75) {
        DrawTexture(vol_7, 885 + k, 876, WHITE);
    } else if (masterSoundControl > 0.75 && masterSoundControl <= 0.85) {
        DrawTexture(vol_8, 885 + k, 876, WHITE);
    } else if (masterSoundControl > 0.85 && masterSoundControl <= 0.95) {
        DrawTexture(vol_9, 885 + k, 876, WHITE);
    } else if (masterSoundControl > 0.95 && masterSoundControl <= 1.05) {
        DrawTexture(vol_10, 885 + k, 876, WHITE);
    } else {

    }

    switch (cursor) {
        case 0:
            DrawTexture(resume_markiert, 456, 400, WHITE);
            break;
        case 1:
            DrawTexture(restart_markiert, 456, 500, WHITE);
            break;
        case 2:
            DrawTexture(mainmenu_markiert, 456, 600, WHITE);
            break;
        case 3:
            DrawTexture(quit_game_markiert, 456, 700, WHITE);
            break;
        case 4:
            if(_musicconfig){
                DrawTexture(musicsound_selected,6 + k, 876,WHITE);
                DrawTexture(music_markiert,10 + k, 829,WHITE);
            }else{
                DrawTexture(music_markiert,10 + k, 829,WHITE);
            }
            break;
        case 5:
            if(_soundconfig){
                DrawTexture(musicsound_selected,885 + k, 876,WHITE);
                DrawTexture(sound_markiert,894 + k, 829,WHITE);
            }else{
                DrawTexture(sound_markiert,894 + k, 829,WHITE);
            }
            break;
        default:
            break;
    }
    //DrawTexture(strich,342 + (((masterMusicControl * 10) * 2) * 7), 771,WHITE);
    //DrawTexture(strich,992 + (((masterSoundControl * 10) * 2) * 7), 771,WHITE);
}

pausescreen::pausescreen() {
}

void pausescreen::musicconfig() {
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        if(masterMusicControl > 0){
            masterMusicControl = masterMusicControl - 0.1;
            soundplayer.menuControll_sound();
        }
    }

    if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        if(masterMusicControl < 1.0){
            masterMusicControl = masterMusicControl + 0.1;
            soundplayer.menuControll2_sound();
        }
    }
}

void pausescreen::soundconfig() {
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        if(masterSoundControl > 0){
            masterSoundControl = masterSoundControl - 0.1;
            soundplayer.menuControll_sound();
        }
    }

    if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        if(masterSoundControl < 1.0){
            masterSoundControl = masterSoundControl + 0.1;
            soundplayer.menuControll2_sound();
        }
    }
}