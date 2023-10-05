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
            soundplayerPtr->menuControll_sound();

            if(cursor == 3){
                cursor = 3;
            }else if(cursor == 4 || cursor == 5){

            }else{
                cursor++;
            }
        }
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
            soundplayerPtr->menuControll2_sound();

            if(cursor == 5 || cursor == 4){
                cursor = 3;
            }else{
                cursor--;
            }
        }
        if (cursor < 0) {
            cursor = 0;
        }


        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
            soundplayerPtr->menuControll_sound();

            if(cursor == 0 || cursor == 1 || cursor == 2 || cursor == 3){
                cursor = 4;
            } else if (cursor == 4) {
                cursor = 5;
            } else if (cursor == 5) {
                cursor = 3;
            }
        } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
            soundplayerPtr->menuControll2_sound();

            if(cursor == 0 || cursor == 1 || cursor == 2 || cursor == 3){
                cursor = 5;
            } else if (cursor == 4) {
                cursor = 3;
            } else if (cursor == 5) {
                cursor = 4;
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
    DrawTexture(hintergrund,0,0,WHITE);
}

bool mainmenu::IsMusicMuted() {
    return sound;
}

void mainmenu::buttons() {
    if(counter >= 200){
        DrawTextureRec(unglitch, Rectangle{age * 784, 0, 784, 208}, Vector2{245, 100}, WHITE);
        age++;
        if(age >= 8){
            counter = 0;
            age = 0;
        }
    }else{
        DrawTextureRec(unglitch, Rectangle{0, 0, 784, 208}, Vector2{245, 100}, WHITE);
        counter++;
    }
    if(storystate > 0){
        DrawTexture(continuebutton, 527, 615, WHITE);
    }else{
        DrawTexture(Start, 492, 615, WHITE);
    }
    DrawTexture(level_select,465, 685, WHITE);
    DrawTexture(credits,543,755,WHITE);
    DrawTexture(Exit, 504, 864, WHITE);
    DrawTexture(music,126, 843,WHITE);
    DrawTexture(_sound,993, 843,WHITE);


    if (masterMusicControl <= 0.05) {
        DrawTexture(vol_0, 27, 888, WHITE);
    } else if (masterMusicControl > 0.05 && masterMusicControl <= 0.15) {
        DrawTexture(vol_1, 27, 888, WHITE);
    } else if (masterMusicControl > 0.15 && masterMusicControl <= 0.25) {
        DrawTexture(vol_2, 27, 888, WHITE);
    } else if (masterMusicControl > 0.25 && masterMusicControl <= 0.35) {
        DrawTexture(vol_3, 27, 888, WHITE);
    } else if (masterMusicControl > 0.35 && masterMusicControl <= 0.45) {
        DrawTexture(vol_4, 27, 888, WHITE);
    } else if (masterMusicControl > 0.45 && masterMusicControl <= 0.55) {
        DrawTexture(vol_5, 27, 888, WHITE);
    } else if (masterMusicControl > 0.55 && masterMusicControl <= 0.65) {
        DrawTexture(vol_6, 27, 888, WHITE);
    } else if (masterMusicControl > 0.65 && masterMusicControl <= 0.75) {
        DrawTexture(vol_7, 27, 888, WHITE);
    } else if (masterMusicControl > 0.75 && masterMusicControl <= 0.85) {
        DrawTexture(vol_8, 27, 888, WHITE);
    } else if (masterMusicControl > 0.85 && masterMusicControl <= 0.95) {
        DrawTexture(vol_9, 27, 888, WHITE);
    } else if (masterMusicControl > 0.95 && masterMusicControl <= 1.05) {
        DrawTexture(vol_10, 27, 888, WHITE);
    } else {

    }

    if (masterSoundControl <= 0.05) {
        DrawTexture(vol_0, 907, 888, WHITE);
    } else if (masterSoundControl > 0.05 && masterSoundControl <= 0.15) {
        DrawTexture(vol_1, 907, 888, WHITE);
    } else if (masterSoundControl > 0.15 && masterSoundControl <= 0.25) {
        DrawTexture(vol_2, 907, 888, WHITE);
    } else if (masterSoundControl > 0.25 && masterSoundControl <= 0.35) {
        DrawTexture(vol_3, 907, 888, WHITE);
    } else if (masterSoundControl > 0.35 && masterSoundControl <= 0.45) {
        DrawTexture(vol_4, 907, 888, WHITE);
    } else if (masterSoundControl > 0.45 && masterSoundControl <= 0.55) {
        DrawTexture(vol_5, 907, 888, WHITE);
    } else if (masterSoundControl > 0.55 && masterSoundControl <= 0.65) {
        DrawTexture(vol_6, 907, 888, WHITE);
    } else if (masterSoundControl > 0.65 && masterSoundControl <= 0.75) {
        DrawTexture(vol_7, 907, 888, WHITE);
    } else if (masterSoundControl > 0.75 && masterSoundControl <= 0.85) {
        DrawTexture(vol_8, 907, 888, WHITE);
    } else if (masterSoundControl > 0.85 && masterSoundControl <= 0.95) {
        DrawTexture(vol_9, 907, 888, WHITE);
    } else if (masterSoundControl > 0.95 && masterSoundControl <= 1.05) {
        DrawTexture(vol_10, 907, 888, WHITE);
    } else {

    }

    switch (cursor) {
        case 0:
            if(storystate > 0){
                DrawTexture(continuebutton_markiert, 527, 615, WHITE);
            }else{
                DrawTexture(Start_markiert, 492, 615, WHITE);
            }
            break;
        case 1:
            DrawTexture(level_select_markiert, 465, 685, WHITE);
            break;
        case 2:
            DrawTexture(credits_markiert,543,755,WHITE);
            break;
        case 3:
            DrawTexture(Exit_markiert, 504, 864, WHITE);
            break;
        case 4:
            if(_musicconfig){
                DrawTexture(musicsound_selected,27, 888,WHITE);
                DrawTexture(music_markiert,126, 843,WHITE);
            }else{
                DrawTexture(music_markiert,126, 843,WHITE);
            }
            break;
        case 5:
            if(_soundconfig){
                DrawTexture(musicsound_selected,907, 888,WHITE);
                DrawTexture(sound_markiert,993, 843,WHITE);
            }else{
                DrawTexture(sound_markiert,993, 843,WHITE);
            }
            break;
        default:
            break;
    }


    //DrawTexture(strich,342 + (((masterMusicControl * 10) * 2) * 7), 871,WHITE);
    //DrawTexture(strich,992 + (((masterSoundControl * 10) * 2) * 7), 871,WHITE);

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
