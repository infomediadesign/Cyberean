#include "mainmenu.h"

void mainmenu::update(globalState &globalState) {

    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        soundplayerPtr->menuEnter_sound();
        switch (cursor) {
            case 0:
                if(alpha == 0.0f){
                    fadeeffect = true;
                }
                if(storymode == true){
                    storymode = false;
                    fadeeffect = false;
                    alpha = 0.0f;
                    storymodeactive = true;
                    globalState = storymodesection;
                }
                break;
            case 1:
                globalState = levelselection;
                break;
            case 2:
                globalState = creditsscreen;

                break;
            case 3:
                CloseWindow();
                break;
            case 4:
                if(_musicconfig == false){
                    _musicconfig = true;
                }else{
                    _musicconfig = false;
                }
                break;
            case 5:
                if(_soundconfig == false){
                    _soundconfig = true;
                }else{
                    _soundconfig = false;
                }
                break;
            default:
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
            cursor = 5;
        }

        if (cursor > 5) {
            cursor = 0;
        }

        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
            if (cursor == 4) {
                cursor = 5;
                soundplayerPtr->menuControll_sound();
            } else if (cursor == 5) {
                cursor = 4;
                soundplayerPtr->menuControll_sound();
            }
        } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
            if (cursor == 4) {
                cursor = 5;
                soundplayerPtr->menuControll2_sound();
            } else if (cursor == 5) {
                cursor = 4;
                soundplayerPtr->menuControll2_sound();
            }
        }
    }

    if (fadeeffect) {
        alpha += fadeSpeed * GetFrameTime();

        if (alpha >= 1.0f) {
            alpha = 0.0f;
            fadeeffect = false;
            globalState = storymodesection;
        }
    }

}

void mainmenu::draw() {
    //DrawTexture(windowsoli,0,0,WHITE);
}

bool mainmenu::IsMusicMuted() {
    return sound;
}

void mainmenu::buttons() {
    DrawTexture(background, 0, -50, WHITE);
    DrawTexture(Start, 368, 400, WHITE);
    DrawTexture(level_select,335, 500, WHITE);
    DrawTexture(credits,337,610,WHITE);
    DrawTexture(Exit, 368, 722, WHITE);
    DrawTexture(music,0, 850,WHITE);
    DrawTexture(_sound,650, 850,WHITE);
    /*if (sound == true) {
        DrawTexture(Unmuted_dunkel, 368, 700, WHITE);
    } else {
        DrawTexture(Muted_dunkel, 368, 700, WHITE);
    }*/
    switch (cursor) {
        case 0:
            DrawTexture(Start_markiert, 368, 400, WHITE);
            break;
        case 1:
            DrawTexture(level_select_markiert, 335, 500, WHITE);
            break;
        case 2:
            DrawTexture(credits_markiert,337,610,WHITE);
            break;
        case 3:
            DrawTexture(Exit_markiert, 368, 722, WHITE);
            break;
        case 4:
            if(_musicconfig){
                DrawTexture(music_markiert_ausgewaehlt,0, 850,WHITE);
            }else{
                DrawTexture(music_markiert,0, 850,WHITE);
            }
            break;
        case 5:
            if(_soundconfig){
                DrawTexture(sound_markiert_ausgewaehlt,650, 850,WHITE);
            }else{
                DrawTexture(sound_markiert,650, 850,WHITE);
            }
            break;
        default:
            break;
    }
    DrawTexture(strich,342 + (((masterMusicControl * 10) * 2) * 7), 871,WHITE);
    DrawTexture(strich,992 + (((masterSoundControl * 10) * 2) * 7), 871,WHITE);


    if(storymodeactive == false){
        DrawTexturePro(fadeTexture,
                       Rectangle{0, 0, (float)fadeTexture.width, (float)fadeTexture.height},
                       Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                       {}, 0, Fade(WHITE, alpha));
    }
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
